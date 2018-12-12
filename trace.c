/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:13 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/12 18:44:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include <stdio.h>

void		fill_map(t_env data)
{
	float		scale;
	int			x;
	int			y;
	int			k;

	scale = ft_fmin((float)data.s_width / (float)data.map_width,
			(float)data.s_height / (float)data.map_height);
	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			data.map[k].x = x * scale;
			data.map[k].y = y * scale;
			x++;
			k++;
		}
		y++;
	}
}

t_coord2	iso_project(t_coord3 t, t_env data)
{
	t_coord2	res;

	res.x = data.start.x + data.scale.x * (t.x - t.y) * cos(0.523599);
	res.y = data.start.y + data.scale.x * (-(float)(t.z * data.scale.z) +
			(t.x + t.y) * sin(0.523599));
	return (res);
}

void		set_ranges(t_env *data)
{
	t_coord2	right;
	t_coord2	left;
	t_coord2	up;
	t_coord2	down;

	up = iso_project(data->map[0], *data);
	right = iso_project(data->map[data->map_width - 1], *data);
	left = iso_project(data->map[data->map_width *
			(data->map_height - 1)], *data);
	down = iso_project(data->map[data->map_width *
			data->map_height - 1], *data);
	data->scale.x = (float)data->s_width / (float)(right.x - left.x);
	data->scale.y = (float)data->s_height / (float)(down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y);
	data->z_delta = 1.5 * 1 / pow(10, ft_count(max3(data->map, data->map_height
					* data->map_width, 'z')) - 2);
	printf("z max = %d\n", (max3(data->map, data->map_height *
					data->map_width, 'z')));
	data->start.x = ft_abs(left.x) * data->scale.x;
	data->start.y = ft_abs(up.y) * data->scale.x;
}

void		trace(t_env data)
{
	int	y;
	int	x;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1)
				plot_line(iso_project(data.map[k], data),
						iso_project(data.map[k + 1], data), data);
			if (y < data.map_height - 1)
				plot_line(iso_project(data.map[k], data),
						iso_project(data.map[k + data.map_width], data), data);
			x++;
			k++;
		}
		y++;
	}
}
