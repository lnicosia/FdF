/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 11:46:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"
#include "fill_poly_utils.h"
#include <stdio.h>
#include <mlx.h>

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

void		fill_ztriangle(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 c2, t_env *data)
{
	t_coord2	max;
	t_coord2	min;
	t_coord2	p;
	t_fcoord3	w;
	float		z;
	float		light;

	max.x = max_3(c0.x, c1.x, c2.x);
	max.x = max.x < data->config.s_width ? max.x : data->config.s_width;
	max.y = max_3(c0.y, c1.y, c2.y);
	max.y = max.y < data->config.s_height? max.y : data->config.s_height;
	min.x = min_3(c0.x, c1.x, c2.x);
	min.y = min_3(c0.y, c1.y, c2.y);
	p.y = min.y < 0 ? 0 : min.y;
	while (p.y < max.y)
	{
		p.x = min.x < 0 ? 0 : min.x;
		while (p.x < max.x)
		{
			w.x = edge(c0, c1, new_fcoord3(p.x, p.y, 0));
			w.y = edge(c1, c2, new_fcoord3(p.x, p.y, 0));
			w.z = edge(c2, c0, new_fcoord3(p.x, p.y, 0));
			if ((data->norm == -1 && w.x >= 0 && w.y >= 0 && w.z >= 0) || (data->norm == 1 && w.x <= 0 && w.y <= 0 && w.z <= 0))
			{
				w.x /= data->area;
				w.y /= data->area;
				w.z /= data->area;
				//z = -(w.x * c2.z + w.y * c0.z + w.z * c1.z);
				z = -(c2.z + w.y * (c0.z - c2.z) + w.z * (c1.z - c2.z));
				light = (ft_fabs(-z - data->fzmin) / ft_fabs(data->fzmax - data->fzmin));
				if (data->config.debug == 1)
					//light = light * 191 + 64;
					light = light * 255;
				if (z < data->zbuffer[p.x + p.y * data->config.s_width])
				{
					data->zbuffer[p.x + p.y * data->config.s_width] = z;
					if (data->config.debug == 1)
						data->img.str[p.x + p.y * data->config.s_width] = 65536 * (int)light + 256 * (int)light + (int)light;
					else
						if (data->config.light == 1)
							data->img.str[p.x + p.y * data->config.s_width] = 65536 * (int)(light * (data->current_color >> 16 & 0xFF)) + 256 * (int)(light * (data->current_color >> 8 & 0xFF)) + (int)(light * (data->current_color & 0xFF));
						else
							data->img.str[p.x + p.y * data->config.s_width] = data->current_color;
				}
			}
			p.x++;
		}
		p.y++;
	}
}

void		find_vertices(t_fcoord3 vertices[3], int k, t_env *data)
{
	int			color;

	if (data->config.debug == 1 || data->config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if ((data->config.poly == 0 && (data->map[k].z + data->map[k + data->map_width + 1].z) / 2 >= (data->map[k + 1].z + data->map[k + data->map_width].z) / 2) || (data->config.poly == 1 && data->map[k].z != data->map[k + data->map_width + 1].z && data->map[k + 1].z == data->map[k + data->map_width].z) || (data->config.poly == 2 && data->map[k].z == data->map[k + data->map_width + 1].z && data->map[k + 1].z != data->map[k + data->map_width].z))
	{
		vertices[0] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y, data->rotated_map[k + 1].z);
		vertices[1] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y, data->rotated_map[k].z);
		vertices[2] = new_fcoord3(data->moved_map[k + data->map_width].x, data->moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
		data->area = edge(vertices[0], vertices[1], vertices[2]);
	}
	else
	{
		vertices[0] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->map_width + 1].z);
		vertices[1] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y, data->rotated_map[k + 1].z);
		vertices[2] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y, data->rotated_map[k].z);
		data->area = edge(vertices[0], vertices[1], vertices[2]);
	}
}

void		find_vertices2(t_fcoord3 vertices2[3], int k, t_env *data)
{
	int			color;

	if (data->config.debug == 1 || data->config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if ((data->config.poly == 0 && (data->map[k].z + data->map[k + data->map_width + 1].z) / 2 >= (data->map[k + 1].z + data->map[k + data->map_width].z) / 2) || (data->config.poly == 1 && data->map[k].z != data->map[k + data->map_width + 1].z && data->map[k + 1].z == data->map[k + data->map_width].z) || (data->config.poly == 2 && data->map[k].z == data->map[k + data->map_width + 1].z && data->map[k + 1].z != data->map[k + data->map_width].z))
	{
		vertices2[0] = new_fcoord3(data->moved_map[k + data->map_width].x, data->moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
		vertices2[1] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->map_width + 1].z);
		vertices2[2] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y, data->rotated_map[k + 1].z);
		data->area = edge(vertices2[0], vertices2[1], vertices2[2]);
	}
	else
	{
		vertices2[0] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y, data->rotated_map[k].z);
		vertices2[1] = new_fcoord3(data->moved_map[k + data->map_width].x, data->moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
		vertices2[2] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->map_width + 1].z);
		data->area = edge(vertices2[0], vertices2[1], vertices2[2]);
	}
}

void		trace_z(t_fcoord3 vertices[3], t_env *data)
{
	t_coord2	line[2];

	line[0] = new_coord2(vertices[0].x, vertices[0].y);
	line[1] = new_coord2(vertices[1].x, vertices[1].y);
	plot_line_z(line, *data, data->edges_color, vertices);
	line[0] = new_coord2(vertices[1].x, vertices[1].y);
	line[1] = new_coord2(vertices[2].x, vertices[2].y);
	plot_line_z(line, *data, data->edges_color, vertices);
	line[0] = new_coord2(vertices[2].x, vertices[2].y);
	line[1] = new_coord2(vertices[0].x, vertices[0].y);
	if (data->config.centers == 2)
		plot_line_z(line, *data, data->edges_color, vertices);
}

void		fill_obj(t_env *data)
{
	int			x;
	int			y;
	int			k;
	t_fcoord3	vertices[3];
	t_fcoord3	vertices2[3];

	y = 0;
	k = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width - 1 && y < data->map_height - 1)
			{
				if (data->config.fill == 1)
					data->current_color = get_color(x, y, *data);
				else
					data->current_color = data->background_color;
				find_vertices(vertices, k, data);
				data->norm = ((vertices[1].x - vertices[0].x) * (vertices[2].y - vertices[0].y) - (vertices[1].y - vertices[0].y) * (vertices[2].x - vertices[0].x)) > 0 ? 1 : -1;
				fill_ztriangle(vertices[0], vertices[1], vertices[2], data);
				if (data->config.trace == 1 || (data->config.fill == 0 && data->config.debug == 0))
					trace_z(vertices, data);
				if (data->config.trace == 1 && data->config.centers == 1)
					middle_of_face(new_coord2((data->moved_map[k + data->map_width + 1].x + data->moved_map[k].x + data->moved_map[k + 1].x + data->moved_map[k + data->map_width].x) / 4, (data->moved_map[k + data->map_width + 1].y + data->moved_map[k].y + data->moved_map[k + 1].y + data->moved_map[k + data->map_width].y) / 4), data->edges_color, *data);
				find_vertices2(vertices2, k, data);
				data->norm = ((vertices2[1].x - vertices2[0].x) * (vertices2[2].y - vertices2[0].y) - (vertices2[1].y - vertices2[0].y) * (vertices2[2].x - vertices2[0].x)) > 0 ? 1 : -1;
				fill_ztriangle(vertices2[0], vertices2[1], vertices2[2], data);
				if (data->config.trace == 1 || (data->config.fill == 0 && data->config.debug == 0))
					trace_z(vertices2, data);
				if (data->config.trace == 1 && data->config.centers == 1)
					middle_of_face(new_coord2((data->moved_map[k + data->map_width + 1].x + data->moved_map[k].x + data->moved_map[k + 1].x + data->moved_map[k + data->map_width].x) / 4, (data->moved_map[k + data->map_width + 1].y + data->moved_map[k].y + data->moved_map[k + 1].y + data->moved_map[k + data->map_width].y) / 4), data->edges_color, *data);
			}
			x++;
			k++;
		}
		y++;
	}
	flush_zbuffer(data);
}
