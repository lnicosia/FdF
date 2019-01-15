/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/15 12:57:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"
#include "plot_line_z.h"
#include <stdio.h>
#include <mlx.h>

int			min_3(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

int			max_3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

void		flush_zbuffer(t_env data)
{
	int	x;
	int	y;
	int	k;

	y = 0;
	k = 0;
	while (y < data.config.s_height)
	{
		x = 0;
		while (x < data.config.s_width)
		{
			data.zbuffer[k] = 2147483647;
			x++;
			k++;
		}
		y++;
	}
}

int			edge(t_fcoord3 c0, t_fcoord3 c1, t_coord2 p)
{
	return ((p.x - c0.x) * (c1.y - c0.y) - (p.y - c0.y) * (c1.x - c0.x));
}

void		fill_ztriangle(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 c2, t_env data)
{
	t_coord2	max;
	t_coord2	min;
	t_coord2	p;
	t_coord2	line[2];
	float		z;

	max.x = max_3(c0.x, c1.x, c2.x);
	max.x = max.x < data.config.s_width ? max.x : data.config.s_width;
	max.y = max_3(c0.y, c1.y, c2.y);
	max.y = max.y < data.config.s_height? max.y : data.config.s_height;
	min.x = min_3(c0.x, c1.x, c2.x);
	min.y = min_3(c0.y, c1.y, c2.y);
	p.y = min.y < 0 ? 0 : min.y;
	z = -(c0.z + c1.z + c2.z) / 3;
	if (data.config.trace == 1)
	{
	line[0] = new_coord2(c0.x, c0.y);
	line[1] = new_coord2(c1.x, c1.y);
	plot_line_z(line, data, 0xFFFFFF, z);
	line[0] = new_coord2(c1.x, c1.y);
	line[1] = new_coord2(c2.x, c2.y);
	plot_line_z(line, data, 0xFFFFFF, z);
	line[0] = new_coord2(c2.x, c2.y);
	line[1] = new_coord2(c0.x, c0.y);
	plot_line_z(line, data, 0xFFFFFF, z);
	}
	//printf("%f\n", z);
	while (p.y < max.y)
	{
		p.x = min.x < 0 ? 0 : min.x;
		while (p.x < max.x)
		{
			if (edge(c0, c1, p) < 1 && edge(c1, c2, p) < 1 && edge(c2, c0, p) < 1)
			{
				if (z < data.zbuffer[p.x + p.y * data.config.s_width])
				{
					data.zbuffer[p.x + p.y * data.config.s_width] = z;
					if (data.config.debug == 1)
						data.img.str[p.x + p.y * data.config.s_width] = 65536 * (int)((ft_fabs(-z - data.fzmin) / ft_fabs(data.fzmax - data.fzmin)) * 255) + 256 * (int)((ft_fabs(-z - data.fzmin) / ft_fabs(data.fzmax - data.fzmin)) * 255) + (int)((ft_fabs(-z - data.fzmin) / ft_fabs(data.fzmax - data.fzmin)) * 255);
					else
						//data.img.str[p.x + p.y * data.config.s_width] = 0;
						data.img.str[p.x + p.y * data.config.s_width] = data.background_color;
				}
			}
			/*else if (edge(c0, c1, p) > -2 && edge(c0, c1, p) <= 0)
				data.img.str[p.x + p.y * data.config.s_width] = 0xFF0000;*/
			p.x++;
		}
		p.y++;
	}
}

void		fill_obj(t_env data)
{
	int		x;
	int		y;
	int		k;
	int		color;

	if (data.config.black_white == 0)
		color = data.background_color;
	else
		color = 0xFFFFFF;
	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1 && y < data.map_height - 1)
			{
				//printf("[%d][%d]\n", y, x);
				fill_ztriangle(new_fcoord3(data.moved_map[k].x, data.moved_map[k].y, data.rotated_map[k].z), new_fcoord3(data.moved_map[k + 1].x, data.moved_map[k + 1].y, data.rotated_map[k + 1].z), new_fcoord3(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y, data.rotated_map[k + data.map_width + 1].z), data);
			/*if (data.config.trace == 1)
			{
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + 1].x, data.moved_map[k + 1].y), data, get_color(x, y, data));
				if (data.config.centers == 2)
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
				plot_line(new_coord2(data.moved_map[k + 1].x, data.moved_map[k + 1].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
			}*/
				fill_ztriangle(new_fcoord3(data.moved_map[k].x, data.moved_map[k].y, data.rotated_map[k].z), new_fcoord3(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y, data.rotated_map[k + data.map_width + 1].z), new_fcoord3(data.moved_map[k + data.map_width].x, data.moved_map[k + data.map_width].y, data.rotated_map[k + data.map_width].z), data);
			/*if (data.config.trace == 1)
			{
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width].x, data.moved_map[k + data.map_width].y), data, get_color(x, y, data));
				if (data.config.centers == 2)
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
				plot_line(new_coord2(data.moved_map[k + data.map_width].x, data.moved_map[k + data.map_width].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
			}*/
				if (data.config.centers == 1)
					middle_of_face(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), data.centers_color, data);
			}
			x++;
			k++;
		}
		y++;
	}
	flush_zbuffer(data);
}
