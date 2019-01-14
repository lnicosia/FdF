/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/14 12:47:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"
#include <stdio.h>
#include <mlx.h>

void		fill_poly(t_coord2 c, unsigned int color, t_env data)
{
	if(color == data.background_color) return;

	int				x1;
	int 			spanAbove;
	int				spanBelow;
	t_coord_stack	*stack;

	stack = NULL;
	push_stack(&stack, c.x, c.y);
	while(pop_stack(&stack, &c.x, &c.y) && c.x >= 0 && c.y >= 0 && c.x < data.config.s_width && c.y < data.config.s_height)
	{
		x1 = c.x;
		while(x1 >= 0 && data.img.str[c.y * data.config.s_width + x1] != data.edges_color)
			x1--;
		x1++;
		spanAbove = 0;
		spanBelow = 0;
		while(x1 < data.config.s_width && data.img.str[c.y * data.config.s_width + x1] != data.edges_color)
		{
			data.img.str[c.y * data.config.s_width + x1] = color;
			if(!spanAbove && c.y > 1 && data.img.str[(c.y - 1) * data.config.s_width + x1] == data.background_color)
			{
				push_stack(&stack, x1, c.y - 1);
				spanAbove = 1;
			}
			else if(spanAbove && c.y > 1 && data.img.str[(c.y - 1) * data.config.s_width + x1] != data.background_color)
			{
				spanAbove = 0;
			}
			if(!spanBelow && c.y < data.config.s_height - 1 && data.img.str[(c.y + 1) * data.config.s_width + x1] == data.background_color)
			{
				push_stack(&stack, x1, c.y + 1);
				spanBelow = 1;
			}
			else if(spanBelow && c.y < data.config.s_height - 1 && data.img.str[(c.y + 1) * data.config.s_width + x1] != data.background_color)
			{
				spanBelow = 0;
			}
			x1++;
		}
	}
}

void		fill_zbuffer(t_coord2 c, float z, t_env data)
{
	int				x1;
	int 			spanAbove;
	int				spanBelow;
	t_coord_stack	*stack;

	stack = NULL;
	push_stack(&stack, c.x, c.y);
	while(pop_stack(&stack, &c.x, &c.y) && c.x >= 0 && c.y >= 0 && c.x < data.config.s_width && c.y < data.config.s_height)
	{
		x1 = c.x;
		while(x1 >= 0 && data.img.str[c.y * data.config.s_width + x1] != data.edges_color)
			x1--;
		x1++;
		spanAbove = 0;
		spanBelow = 0;
		while(x1 < data.config.s_width && data.img.str[c.y * data.config.s_width + x1] != data.edges_color)
		{
			if (data.zbuffer[c.y * data.config.s_width + x1] > z)
				data.zbuffer[c.y * data.config.s_width + x1] = z;
			data.img.str[c.y * data.config.s_width + x1] = 0x01FF0000;
			if(!spanAbove && c.y > 1 && data.img.str[(c.y - 1) * data.config.s_width + x1] == data.background_color)
			{
				push_stack(&stack, x1, c.y - 1);
				spanAbove = 1;
			}
			else if(spanAbove && c.y > 1 && data.img.str[(c.y - 1) * data.config.s_width + x1] != data.background_color)
			{
				spanAbove = 0;
			}
			if(!spanBelow && c.y < data.config.s_height - 1 && data.img.str[(c.y + 1) * data.config.s_width + x1] == data.background_color)
			{
				push_stack(&stack, x1, c.y + 1);
				spanBelow = 1;
			}
			else if(spanBelow && c.y < data.config.s_height - 1 && data.img.str[(c.y + 1) * data.config.s_width + x1] != data.background_color)
			{
				spanBelow = 0;
			}
			x1++;
		}
	}
}

t_coord2	start_pixel(int k, t_env data)
{
	if (data.moved_map[k + 1].x >= data.moved_map[k].x)
	{
		if (data.moved_map[k + data.map_width].y >= data.moved_map[k].y)
			return (new_coord2(data.moved_map[k].x + 1, data.moved_map[k].y + 1));
		else
			return (new_coord2(data.moved_map[k].x + 1, data.moved_map[k].y - 1));
	}
	else
		if (data.moved_map[k + data.map_width].y >= data.moved_map[k].y)
			return (new_coord2(data.moved_map[k].x - 1, data.moved_map[k].y + 1));
		else
			return (new_coord2(data.moved_map[k].x - 1, data.moved_map[k].y - 1));
}

void		print_zbuffer(t_env data)
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
			if (data.zbuffer[k] != 2147483647)
			{
				data.img.str[k] = 65536 * (int)((data.zbuffer[k] / data.zmax) * 255);
				//data.img.str[k] = 0xFFFFFF;
			}
			x++;
			k++;
		}
		y++;
	}
}

void		fill_obj(t_env data)
{
	int		x;
	int		y;
	int		k;
	int		color;
	float	z;

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
				z = (data.rotated_map[k].z + data.rotated_map[k + 1].z + data.rotated_map[k + data.map_width].z + data.rotated_map[k + data.map_width + 1].z) / 4;
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + 1].x, data.moved_map[k + 1].y), data, get_color(x, y, data));
				plot_line(new_coord2(data.moved_map[k + 1].x, data.moved_map[k + 1].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
				//fill_poly(start_pixel(k, data), get_color(x, y, data), data);
				//fill_poly(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), get_color(x, y, data), data);
				//fill_poly(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), 0, data);
				fill_zbuffer(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), z, data);
				/*if (k == 20)
				{
				mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
				break;
				}*/
				set_background(data, color);
				if (k == 50)
					break;
				//plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
			}
			x++;
			k++;
		}
		y++;
	}
	print_zbuffer(data);
}
