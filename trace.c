/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/12 15:28:35 by lnicosia         ###   ########.fr       */
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

	scale = ft_fmin(data.s_width / data.map_width,
			data.s_height / data.map_height);
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
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	up.x = 0;
	up.y = 0;
	left.x = -(float)data->map_height * cos(0.523599);
	left.y = (float)data->map_height * sin(0.523599);
	right.x = (float)data->map_width * cos(0.523599);
	right.y = (float)data->map_width * sin(0.523599);
	down.x = ((float)data->map_width - (float)data->map_height) * cos(0.523599);
	down.y = ((float)data->map_width + (float)data->map_height) * sin(0.523599);
	printf("up.x = %f up.y = %f\n", up.x, up.y);
	printf("down.x = %f down.y = %f\n", down.x, down.y);
	printf("left.x = %f left.y = %f\n", left.x, left.y);
	printf("right.x = %f right.y = %f\n", right.x, right.y);
	data->scale.x = (float)data->s_width / (float)(right.x - left.x);
	data->scale.y = (float)data->s_height / (float)(down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y);
	data->start.x = ft_abs(left.x) * data->scale.x;
	data->start.y = ft_abs(up.y) * data->scale.x;
	//data->start.y = ft_fmax(ft_abs(up.y) * data->scale.x, max3(data->map, data->map_height * data->map_width, 'z'));
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
