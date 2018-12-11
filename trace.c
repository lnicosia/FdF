/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 17:23:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include <stdio.h>

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -(z) + (previous_x + previous_y) * sin(0.523599);
}

void		fill_map(t_env data)
{
	float		x_scale;
	float		y_scale;
	int			x;
	int			y;
	int			k;

	x_scale = data.s_width / data.map_width;
	y_scale = data.s_height / data.map_height;
	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			data.map[k].x = x * x_scale;
			data.map[k].y = y * y_scale;
			x++;
			k++;
		}
		y++;
	}
}

void		get_ranges(t_env *data)
{
	t_coord3	min;
	t_coord3	max;

	max.x = max3(data->map, data->map_height * data->map_width, 'x');
	max.y = max3(data->map, data->map_height * data->map_width, 'y');
	min.x = min3(data->map, data->map_height * data->map_width, 'x');
	min.y = min3(data->map, data->map_height * data->map_width, 'y');
	max.z = max3(data->map, data->map_height * data->map_width, 'z');
	min.z = min3(data->map, data->map_height * data->map_width, 'z');
	data->z_scale = (float)data->map_height / (float)(max.z - min.z);
	data->x_scale = (float)data->s_width / (float)(max.x - min.x);
	data->y_scale = (float)data->s_height / (float)(max.y - min.y);
	data->start.x = ft_abs(min.x * data->x_scale);
	data->start.y = ft_abs(min.y * data->y_scale);
}

void		project(t_env data)
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
			iso(&data.map[k].x, &data.map[k].y, data.map[k].z);
			x++;
			k++;
		}
		y++;
	}
}

void		scale(t_env data)
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
			data.map[k].x *= data.x_scale;
			data.map[k].y *= data.y_scale;
			x++;
			k++;
		}
		y++;
	}
}

void		trace(t_env data)
{
	int	y;
	int	x;
	int	k;

	project(data);
	get_ranges(&data);
	scale(data);
	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1)
				plot_line(new_coord2(data.map[k].x + data.start.x, data.map[k].y + data.start.y), new_coord2(data.map[k + 1].x + data.start.x, data.map[k + 1].y + data.start.y), data);
			if (y < data.map_height - 1)
				plot_line(new_coord2(data.map[k].x + data.start.x, data.map[k].y + data.start.y), new_coord2(data.map[k + data.map_width].x + data.start.x, data.map[k + data.map_width].y + data.start.y), data);
			x++;
			k++;
		}
		y++;
	}
}
