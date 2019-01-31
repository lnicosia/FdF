/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_computing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:38:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/31 17:45:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"
#include "fill_poly_utils.h"

void	clear_zbuffer(t_env *data)
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

void	set_pixel(t_coord2 p, float light, t_env *data)
{
	if (data->config.debug == 1)
		data->img.str[p.x + p.y * data->config.s_width] = 65536
			* (int)light + 256 * (int)light + (int)light;
	else
	{
		if (data->config.light == 1)
			data->img.str[p.x + p.y * data->config.s_width] =
				65536 * (int)(light * data->red) + 256 *
				(int)(light * data->green) + (int)(light *
						data->blue);
		else
			data->img.str[p.x + p.y * data->config.s_width] =
				data->current_color;
	}
}

void	compute_triangle(t_fcoord3 v[3], t_coord2 p, t_env *data)
{
	t_fcoord3	w;
	float		z;
	float		light;

	w.x = edge(v[0], v[1], new_fcoord3(p.x, p.y, 0));
	w.y = edge(v[1], v[2], new_fcoord3(p.x, p.y, 0));
	w.z = edge(v[2], v[0], new_fcoord3(p.x, p.y, 0));
	if ((data->norm == -1 && w.x >= 0 && w.y >= 0 && w.z >= 0) ||
			(data->norm == 1 && w.x <= 0 && w.y <= 0 && w.z <= 0))
	{
		w.x /= data->area;
		w.y /= data->area;
		w.z /= data->area;
		z = -(v[2].z + w.y * data->c0_c2 + w.z * data->c1_c2);
		light = ft_fabs(-z - data->fzmin) / data->light_range;
		if (data->config.debug == 1)
			light = light * 255;
		if (z < data->zbuffer[p.x + p.y * data->config.s_width])
		{
			data->zbuffer[p.x + p.y * data->config.s_width] = z;
			set_pixel(p, light, data);
		}
	}
}

void	fill_triangle(t_fcoord3 v[3], t_env *data)
{
	t_coord2	max;
	t_coord2	min;
	t_coord2	p;

	max.x = max_3(v[0].x, v[1].x, v[2].x);
	max.x = max.x < data->config.s_width ? max.x : data->config.s_width;
	max.y = max_3(v[0].y, v[1].y, v[2].y);
	max.y = max.y < data->config.s_height ? max.y : data->config.s_height;
	min.x = min_3(v[0].x, v[1].x, v[2].x);
	min.y = min_3(v[0].y, v[1].y, v[2].y);
	p.y = min.y < 0 ? 0 : min.y;
	while (p.y < max.y)
	{
		p.x = min.x < 0 ? 0 : min.x;
		while (p.x < max.x)
		{
			compute_triangle(v, p, data);
			p.x++;
		}
		p.y++;
	}
}

void	trace_z(t_fcoord3 v[3], t_env *data)
{
	t_coord2	line[2];

	line[0] = new_coord2(v[0].x, v[0].y);
	line[1] = new_coord2(v[1].x, v[1].y);
	plot_line_z(line, *data, data->edges_color, v);
	line[0] = new_coord2(v[1].x, v[1].y);
	line[1] = new_coord2(v[2].x, v[2].y);
	plot_line_z(line, *data, data->edges_color, v);
	line[0] = new_coord2(v[2].x, v[2].y);
	line[1] = new_coord2(v[0].x, v[0].y);
	if (data->config.centers == 2)
		plot_line_z(line, *data, data->edges_color, v);
}
