/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 18:47:36 by lnicosia         ###   ########.fr       */
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

t_coord2	iso_project(t_coord3 t, float scale)
{
	t_coord2	res;

	res.x = (t.x - t.y) * cos(0.523599);
	res.y = -(t.z * scale) + (t.x + t.y) * sin(0.523599);
	return (res);
}

void		get_ranges(t_env *data)
{
	t_coord2	right;
	t_coord2	left;
	t_coord2	up;
	t_coord2	down;

	up = iso_project(data->map[0], 1);
	right = iso_project(data->map[data->map_width - 1], 1);
	left = iso_project(data->map[data->map_width * (data->map_height - 1)], 1);
	down = iso_project(data->map[data->map_width * data->map_height - 1], 1);
	ft_putstr("up: x = "); ft_putnbr(up.x); ft_putstr(" y = "); ft_putnbr(up.y); ft_putchar('\n');
	ft_putstr("down: x = "); ft_putnbr(down.x); ft_putstr(" y = "); ft_putnbr(down.y); ft_putchar('\n');
	ft_putstr("left: x = "); ft_putnbr(left.x); ft_putstr(" y = "); ft_putnbr(left.y); ft_putchar('\n');
	ft_putstr("right: x = "); ft_putnbr(right.x); ft_putstr(" y = "); ft_putnbr(right.y); ft_putchar('\n');
	data->x_scale = ft_fmin(((float)(ft_abs(up.y - down.y)) / (float)data->s_height), (((float)(ft_abs(left.x - right.y)) / (float)data->s_width)));
	printf("scale = %f\n", data->x_scale);
	data->start.y = 1;
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
			data.map[k].y *= data.x_scale;
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

	//project(data);
	get_ranges(&data);
	scale(data);
	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			/*if (x < data.map_width - 1)
				plot_line(new_coord2(data.map[k].x + data.start.x, data.map[k].y + data.start.y), new_coord2(data.map[k + 1].x + data.start.x, data.map[k + 1].y + data.start.y), data);
			if (y < data.map_height - 1)
				plot_line(new_coord2(data.map[k].x + data.start.x, data.map[k].y + data.start.y), new_coord2(data.map[k + data.map_width].x + data.start.x, data.map[k + data.map_width].y + data.start.y), data);*/
			if (x < data.map_width - 1)
				plot_line(iso_project(data.map[k], data.z_scale), iso_project(data.map[k + 1], data.z_scale), data);
			if (y < data.map_height - 1)
				plot_line(iso_project(data.map[k], data.z_scale), iso_project(data.map[k + data.map_width], data.z_scale), data);
			x++;
			k++;
		}
		y++;
	}
}
