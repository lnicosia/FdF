/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/07 17:46:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"
#include <stdio.h>

void	middle_of_face(t_coord2 c, unsigned int color, t_env data)
{
	if (c.x >= 0 && c.x < data.s_width && c.y >= 0 && c.y < data.s_height)
		data.img.str[c.x + c.y * data.s_width] = color;
}

void	fill_poly(t_coord2 c, unsigned int color, t_env data)
{
	if(color == data.background_color) return;

	int				x1;
	int 			spanAbove;
	int				spanBelow;
	t_coord_stack	*stack;

	stack = NULL;
	push_stack(&stack, c.x, c.y);
	while(pop_stack(&stack, &c.x, &c.y) && c.x >= 0 && c.y >= 0 && c.x < data.s_width && c.y < data.s_height)
	{
		x1 = c.x;
		while(x1 >= 0 && data.img.str[c.y * data.s_width + x1] == data.background_color)
			x1--;
		x1++;
		spanAbove = 0;
		spanBelow = 0;
		while(x1 < data.s_width && data.img.str[c.y * data.s_width + x1] == data.background_color)
		{
			data.img.str[c.y * data.s_width + x1] = color;
			if(!spanAbove && c.y > 1 && data.img.str[(c.y - 1) * data.s_width + x1] == data.background_color)
			{
				push_stack(&stack, x1, c.y - 1);
				spanAbove = 1;
			}
			else if(spanAbove && c.y > 1 && data.img.str[(c.y - 1) * data.s_width + x1] != data.background_color)
			{
				spanAbove = 0;
			}
			if(!spanBelow && c.y < data.s_height - 1 && data.img.str[(c.y + 1) * data.s_width + x1] == data.background_color)
			{
				push_stack(&stack, x1, c.y + 1);
				spanBelow = 1;
			}
			else if(spanBelow && c.y < data.s_height - 1 && data.img.str[(c.y + 1) * data.s_width + x1] != data.background_color)
			{
				spanBelow = 0;
			}
			x1++;
		}
	}
}

void	fill_obj(t_env data)
{
	int	x;
	int	y;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1 && y < data.map_height - 1)
			{
				fill_poly(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), get_color(x, y, data), data);
				//fill_poly(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), 0, data);
				middle_of_face(new_coord2((data.moved_map[k + data.map_width + 1].x + data.moved_map[k].x) / 2, (data.moved_map[k + data.map_width + 1].y + data.moved_map[k].y) / 2), get_color(x, y, data), data);
			}
			x++;
			k++;
		}
		y++;
	}
}
