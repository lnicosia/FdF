/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 11:40:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include "color.h"
#include <stdio.h>

unsigned int	get_color(int x, int y, t_env data)
{
	int		z;

	if (data.config.black_white == 1)
		return (0);
	if (data.config.color == 2)
	{
		z = data.map[y * data.map_width + x].z;
		if (z <= 0)
			return (0xC3E1FF);
		if (z <= (data.zmax) / data.color_div)
			return (0x344623);
		if (z <= (2 * data.zmax) / data.color_div)
			return (0x7E9F5D);
		if (z <= (3 * data.zmax) / data.color_div)
			return (0xB7CAA4);
		if (z <= (4 * data.zmax) / data.color_div)
			return (0xCBAC83);
		if (z <= (5 * data.zmax) / data.color_div)
			return (0x75552D);
		return (z <= (6 * data.zmax) / data.color_div ? 0x583405 : (0xFFFFFF));
	}
	else if (data.config.color == 1)
		if (data.config.file_color == 1)
			return (data.file_colors[y * data.map_width + x]);
	return (data.picked_color);
}

void			scale_map(t_env data)
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
			data.projected_map[k].x *= data.scale.x;
			data.projected_map[k].y *= data.scale.x;
			x++;
			k++;
		}
		y++;
	}
}

void			move_map(t_env data)
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
			data.moved_map[k].x = data.projected_map[k].x + data.start.x +
				data.delta_move.x;
			data.moved_map[k].y = data.projected_map[k].y + data.start.y +
				data.delta_move.y;
			x++;
			k++;
		}
		y++;
	}
}

void			trace(t_env data)
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
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y),
						new_coord2(data.moved_map[k + 1].x, data.moved_map[k +
							1].y), data, get_color(x, y, data));
			if (y < data.map_height - 1)
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y),
						new_coord2(data.moved_map[k + data.map_width].x,
							data.moved_map[k + data.map_width].y), data,
						get_color(x, y, data));
			x++;
			k++;
		}
		y++;
	}
}

void			trace_aa(t_env data)
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
				plot_line_aa(new_coord2(data.moved_map[k].x, data.moved_map[k]
			.y), new_coord2(data.moved_map[k + 1].x, data.moved_map[k + 1].y),
						data, get_color(x, y, data));
			if (y < data.map_height - 1)
				plot_line_aa(new_coord2(data.moved_map[k].x,
data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width].x,
data.moved_map[k + data.map_width].y), data, get_color(x, y, data));
			x++;
			k++;
		}
		y++;
	}
}
