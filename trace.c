/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/12 11:55:06 by lnicosia         ###   ########.fr       */
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

t_coord2	iso_project(t_coord3 t, t_env data)
{
	t_coord2	res;

	res.x = data.start.x + data.scale.x * (t.x - t.y ) * cos(0.523599);
	res.y = data.start.y + data.scale.y * (-(t.z * data.scale.z) + (t.x + t.y) * sin(0.523599));
	return (res);
}

void		get_ranges(t_env *data)
{
	t_coord2	right;
	t_coord2	left;
	t_coord2	up;
	t_coord2	down;

	up = iso_project(data->map[0], *data);
	right = iso_project(data->map[data->map_width - 1], *data);
	left = iso_project(data->map[data->map_width * (data->map_height - 1)], *data);
	down = iso_project(data->map[data->map_width * data->map_height - 1], *data);
	ft_putstr("vertical delta  = "); ft_putnbr(down.y - up.y); ft_putstr("\nhorizontal delta = "); ft_putnbr(right.x - left.x); ft_putchar('\n');
	data->scale.x = (float)data->s_width / (float)(right.x - left.x);
	data->scale.y = (float)data->s_height / (float)(down.y - up.y);
	data->start.x = ft_abs(left.x) * data->scale.x;
	data->start.y = ft_abs(up.y) * data->scale.y;
	printf("x_scale = %f\ny_scale = %f\n", data->scale.x, data->scale.y);
	printf("x_start = %d\ny_start = %d\n", data->start.x, data->start.y);
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
			data.map[k].x *= data.scale.x;
			data.map[k].y *= data.scale.y;
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

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1)
				plot_line(iso_project(data.map[k], data), iso_project(data.map[k + 1], data), data);
			if (y < data.map_height - 1)
				plot_line(iso_project(data.map[k], data), iso_project(data.map[k + data.map_width], data), data);
			x++;
			k++;
		}
		y++;
	}
}
