/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:13 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 16:00:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include <stdio.h>

t_coord2	iso_project(t_coord3 c, t_env data)
{
	t_coord2	res;

	res.x = data.start.x + data.scale.x * (c.x - c.y) * cos(0.523599);
	res.y = data.start.y + data.scale.x * (-(float)(c.z * data.scale.z) +
			(c.x + c.y) * sin(0.523599));
	return (res);
}

t_fcoord2	fiso_project(t_coord3 c)
{
	t_fcoord2	res;

	res.x = ((float)c.x - (float)c.y) * cos(0.523599);
	res.y = ((float)c.x + (float)c.y) * sin(0.523599);
	return (res);
}

void		recenter(t_env *data)
{
	t_fcoord2	center;
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	up = fiso_project(data->map[0]);
	right = fiso_project(data->map[data->map_width - 1]);
	left = fiso_project(data->map[data->map_width * (data->map_height - 1)]);
	down = fiso_project(data->map[data->map_width * data->map_height - 1]);
	center.x = data->scale.x * (right.x - left.x) / 2 - ft_fabs(left.x)
		* data->scale.x;
	center.y = data->scale.x * (down.y - up.y) / 2 - ft_fabs(up.y)
		* data->scale.x;
	data->start.x = (float)data->s_width / 2 - center.x;
	data->start.y = (float)data->s_height / 2 - center.y;
}

void		set_ranges(t_env *data)
{
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;
	int			zmax;

	up = fiso_project(data->map[0]);
	right = fiso_project(data->map[data->map_width - 1]);
	left = fiso_project(data->map[data->map_width * (data->map_height - 1)]);
	down = fiso_project(data->map[data->map_width * data->map_height - 1]);
	zmax = (max3(data->map, data->map_height * data->map_width, 'z'));
	printf("[up.x] = %f	[up.y] = %f\n", up.x, up.y);
	printf("[down.x] = %f	[down.y] = %f\n", down.x, down.y);
	printf("[left.x] = %f	[left.y] = %f\n", left.x, left.y);
	printf("[right.x] = %f	[right.y] = %f\n", right.x, right.y);
	data->scale.x = (float)data->s_width / (right.x - left.x);
	data->scale.y = (float)data->s_height / (down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.8;
	data->delta.x = data->scale.x * 10 / 100;
	printf("final scale = %f\n", data->scale.x);
	recenter(data);
	data->scale.z = data->map_height / ((float)zmax * 10);
	printf("scale.z = %f\n", data->scale.z);
	data->delta.z = (float)data->s_height / (100 * zmax * data->scale.x);
	printf("zmax = %d\ndelta.z = %f\n", zmax, data->delta.z);
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
				plot_line(data.project[data.project_type](data.map[k], data),
						data.project[data.project_type](data.map[k + 1], data),
						data, 0xFFFFFF);
			if (y < data.map_height - 1)
				plot_line(data.project[data.project_type](data.map[k], data),
						data.project[data.project_type](data.map[k +
							data.map_width], data), data, 0xFFFFFF);
			x++;
			k++;
		}
		y++;
	}
}
