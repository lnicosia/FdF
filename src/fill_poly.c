/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/31 17:44:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"
#include "fill_poly_utils.h"
#include <stdio.h>
#include <mlx.h>

void	find_v(t_fcoord3 v[3], int k, t_env *data)
{
	if ((data->config.poly == 0 && (data->map[k].z + data->map[k + data->
map_width + 1].z) / 2 >= (data->map[k + 1].z + data->map[k + data->map_width]
.z) / 2) || (data->config.poly == 1 && data->map[k].z != data->map[k + data->
map_width + 1].z && data->map[k + 1].z == data->map[k + data->map_width].z) ||
(data->config.poly == 2 && data->map[k].z == data->map[k + data->map_width + 1]
.z && data->map[k + 1].z != data->map[k + data->map_width].z))
	{
		v[0] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y,
				data->rotated_map[k + 1].z);
		v[1] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y, data->
				rotated_map[k].z);
		v[2] = new_fcoord3(data->moved_map[k + data->map_width].x, data->
moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
	}
	else
	{
		v[0] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->
			moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->
				map_width + 1].z);
		v[1] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y,
				data->rotated_map[k + 1].z);
		v[2] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y,
				data->rotated_map[k].z);
	}
}

void	find_v2(t_fcoord3 v2[3], int k, t_env *data)
{
	if ((data->config.poly == 0 && (data->map[k].z + data->map[k + data->
map_width + 1].z) / 2 >= (data->map[k + 1].z + data->map[k + data->map_width]
.z) / 2) || (data->config.poly == 1 && data->map[k].z != data->map[k + data->
map_width + 1].z && data->map[k + 1].z == data->map[k + data->map_width].z) ||
(data->config.poly == 2 && data->map[k].z == data->map[k + data->map_width + 1]
.z && data->map[k + 1].z != data->map[k + data->map_width].z))
	{
		v2[0] = new_fcoord3(data->moved_map[k + data->map_width].x, data->
moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
		v2[1] = new_fcoord3(data->moved_map[k + data->map_width + 1].x, data->
moved_map[k + data->map_width + 1].y, data->rotated_map[k + data->map_width + 1]
.z);
		v2[2] = new_fcoord3(data->moved_map[k + 1].x, data->moved_map[k + 1].y,
				data->rotated_map[k + 1].z);
	}
	else
	{
		v2[0] = new_fcoord3(data->moved_map[k].x, data->moved_map[k].y,
				data->rotated_map[k].z);
		v2[1] = new_fcoord3(data->moved_map[k + data->map_width].x, data->
	moved_map[k + data->map_width].y, data->rotated_map[k + data->map_width].z);
		v2[2] = new_fcoord3(data->moved_map[k + data->map_width + 1].x,
				data->moved_map[k + data->map_width + 1].y,
				data->rotated_map[k + data->map_width + 1].z);
	}
}

void	pre_compute(t_fcoord3 v[3], int x, int y, t_env *data)
{
	if (data->config.fill == 1)
		data->current_color = get_color(x, y, *data);
	else
		data->current_color = data->background_color;
	data->red = data->current_color >> 16 & 0xFF;
	data->green = data->current_color >> 8 & 0xFF;
	data->blue = data->current_color & 0xFF;
	data->area = edge(v[0], v[1], v[2]);
	data->c0_c2 = v[0].z - v[2].z;
	data->c1_c2 = v[1].z - v[2].z;
	data->norm = ((v[1].x - v[0].x) * (v[2].y - v[0].y) - (v[1].y - v[0].y)
			* (v[2].x - v[0].x)) > 0 ? 1 : -1;
}

void	compute_and_fill(int x, int y, int k, t_env *data)
{
	t_fcoord3	v[3];
	t_fcoord3	v2[3];

	find_v(v, k, data);
	pre_compute(v, x, y, data);
	fill_triangle(v, data);
	if (data->config.trace == 1 || (data->config.fill == 0 && data->
				config.debug == 0) || data->config.debug == 1)
		trace_z(v, data);
	if (data->config.trace == 1 && data->config.centers == 1)
		middle_of_face(k, data->edges_color, *data);
	find_v2(v2, k, data);
	pre_compute(v2, x, y, data);
	fill_triangle(v2, data);
	if (data->config.trace == 1 || (data->config.fill == 0 && data->
				config.debug == 0) || data->config.debug == 1)
		trace_z(v2, data);
	if (data->config.trace == 1 && data->config.centers == 1)
		middle_of_face(k, data->edges_color, *data);
}

void	fill_obj(t_env *data)
{
	int			x;
	int			y;
	int			k;

	y = 0;
	k = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (x < data->map_width - 1 && y < data->map_height - 1)
			{
				compute_and_fill(x, y, k, data);
			}
			x++;
			k++;
		}
		y++;
	}
	clear_zbuffer(data);
}
