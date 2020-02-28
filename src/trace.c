/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:13 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 12:20:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include "color.h"

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
		if (z <= (data.zrange) / data.color_div)
			return (0x344623);
		if (z <= (2 * data.zrange) / data.color_div)
			return (0x7E9F5D);
		if (z <= (3 * data.zrange) / data.color_div)
			return (0xB7CAA4);
		if (z <= (4 * data.zrange) / data.color_div)
			return (0xCBAC83);
		if (z <= (5 * data.zrange) / data.color_div)
			return (0x75552D);
		return (z <= (6 * data.zrange) / data.color_div ? 0x583405 :
				(0xFFFFFF));
	}
	return ((data.config.color == 1 && data.config.file_color == 1) ?
			data.file_colors[y * data.map_width + x] : data.picked_color);
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
					.y), new_coord2(data.moved_map[k + 1].x,
					data.moved_map[k + 1].y), data, get_color(x, y, data));
			if (y < data.map_height - 1)
				plot_line_aa(new_coord2(data.moved_map[k].x,
					data.moved_map[k].y), new_coord2(data.moved_map[k +
					data.map_width].x, data.moved_map[k + data.map_width].y),
						data, get_color(x, y, data));
			x++;
			k++;
		}
		y++;
	}
}
