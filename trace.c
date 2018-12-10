/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 19:10:01 by lnicosia         ###   ########.fr       */
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
	y_scale = data.s_width / data.map_width;
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

void		trace(t_env data, t_img img)
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
				plot_line(new_coord2(data.map[k].x, data.map[k].y),
						new_coord2(data.map[k + 1].x, data.map[k + 1].y),
						img, data);
			if (y < data.map_height - 1)
				plot_line(new_coord2(data.map[k].x, data.map[k].y),
						new_coord2(data.map[k + data.map_width].x,
							data.map[k + data.map_width].y), img, data);
			x++;
			k++;
		}
		y++;
	}
}
