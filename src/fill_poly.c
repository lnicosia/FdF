/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/18 13:04:23 by lnicosia         ###   ########.fr       */
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

void		flush_zbuffer(t_env *data)
{
	int	x;
	int	y;
	int	k;

	y = 0;
	k = 0;
	while (y < data->config.s_height)
	{
		x = 0;
		while (x < data->config.s_width)
		{
			data->zbuffer[k] = 2147483647;
			x++;
			k++;
		}
		y++;
	}
}

float		edge(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 p)
{
	return ((p.x - c0.x) * (c1.y - c0.y) - (p.y - c0.y) * (c1.x - c0.x));
}

void		fill_ztriangle(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 c2, t_env *data)
{
	t_coord2	max;
	t_coord2	min;
	t_coord2	p;
	t_coord2	line[2];
	t_fcoord3	w;
	t_fcoord3	vertices[3];
	float		z;
	float		light;

	max.x = max_3(c0.x, c1.x, c2.x);
	max.x = max.x < data->config.s_width ? max.x : data->config.s_width;
	max.y = max_3(c0.y, c1.y, c2.y);
	max.y = max.y < data->config.s_height? max.y : data->config.s_height;
	min.x = min_3(c0.x, c1.x, c2.x);
	min.y = min_3(c0.y, c1.y, c2.y);
	p.y = min.y < 0 ? 0 : min.y;
	z = -(c0.z + c1.z + c2.z) / 3;
	data->area = edge(c0, c1, c2);
	vertices[0] = c0;
	vertices[1] = c1;
	vertices[2] = c2;
	if (data->config.trace == 1)
	{
		line[0] = new_coord2(c0.x, c0.y);
		line[1] = new_coord2(c1.x, c1.y);
		plot_line_z(line, *data, data->current_color, vertices);
		line[0] = new_coord2(c1.x, c1.y);
		line[1] = new_coord2(c2.x, c2.y);
		plot_line_z(line, *data, data->current_color, vertices);
		line[0] = new_coord2(c2.x, c2.y);
		line[1] = new_coord2(c0.x, c0.y);
		plot_line_z(line, *data, data->current_color, vertices);
	}
	//printf("%f\n", z);
	while (p.y < max.y)
	{
		p.x = min.x < 0 ? 0 : min.x;
		while (p.x < max.x)
		{
			if ((w.x = edge(c0, c1, new_fcoord3(p.x, p.y, 0))) >= 0 && (w.y = edge(c1, c2, new_fcoord3(p.x, p.y, 0))) >= 0 && (w.z = edge(c2, c0, new_fcoord3(p.x, p.y, 0))) >= 0)
			{
				w.x /= data->area;
				w.y /= data->area;
				w.z /= data->area;
				//z = -(w.x * c2.z + w.y * c0.z + w.z * c1.z);
				z = -(c2.z + w.y * (c0.z - c2.z) + w.z * (c1.z - c2.z));
				if (data->config.debug == 1)
					light = (ft_fabs(-z - data->fzmin) / ft_fabs(data->fzmax - data->fzmin) * 127 + 128);
				else
					light = (ft_fabs(-z - data->fzmin) / ft_fabs(data->fzmax - data->fzmin));
				if (z < data->zbuffer[p.x + p.y * data->config.s_width])
				{
					data->zbuffer[p.x + p.y * data->config.s_width] = z;
					if (data->config.debug == 1)
						data->img.str[p.x + p.y * data->config.s_width] = 65536 * (int)light + 256 * (int)light + (int)light;
					else
						//data->img.str[p.x + p.y * data->config.s_width] = 65536 * (int)(light * (color >> 16 & 0xFF)) + 256 * (int)(light * (color >> 8 & 0xFF)) + (int)(light * (color & 0xFF));
						//data->img.str[p.x + p.y * data->config.s_width] = color;
						data->img.str[p.x + p.y * data->config.s_width] = data->background_color;
				}
			}
			p.x++;
		}
		p.y++;
	}
}

void		fill_obj(t_env *data)
{
	int			x;
	int			y;
	int			k;
	t_fcoord3	vertices[3];

	y = 0;
	k = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width - 1 && y < data->map_height - 1)
			{
				data->current_coord = new_coord2(x, y);
				data->current_color = get_color(data->current_coord.x, data->current_coord.y, *data);
				vertices[0] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y, data->rotated_map[k].z);
				vertices[1] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->map_width + 1].z);
				vertices[2] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y, data->rotated_map[k + 1].z);
				fill_ztriangle(vertices[0], vertices[1], vertices[2], data);
				vertices[1] = new_fcoord3(data->moved_map[k + data->map_width].x, data->moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
				vertices[2] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->map_width + 1].z);
				fill_ztriangle(vertices[0], vertices[1], vertices[2], data);
				if (data->config.centers == 1)
					middle_of_face(new_coord2((data->moved_map[k + data->map_width + 1].x + data->moved_map[k].x) / 2, (data->moved_map[k + data->map_width + 1].y + data->moved_map[k].y) / 2), data->centers_color, *data);
			}
			x++;
			k++;
		}
		y++;
	}
	flush_zbuffer(data);
}
