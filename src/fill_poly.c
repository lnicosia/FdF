/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/14 18:46:11 by lnicosia         ###   ########.fr       */
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

void		fill_zbuffer(t_coord2 c, float z, t_env data)
{
	int				x1;
	int 			spanAbove;
	int				spanBelow;
	t_coord_stack	*stack;

	/*if (data.img.str[c.y * data.config.s_width + c.x] == data.picked_color)
	  return ;*/
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
	float		z;

	max.x = max_3(c0.x, c1.x, c2.x);
	max.x = max.x < data.config.s_width ? max.x : data.config.s_width;
	max.y = max_3(c0.y, c1.y, c2.y);
	max.y = max.y < data.config.s_height? max.y : data.config.s_height;
	min.x = min_3(c0.x, c1.x, c2.x);
	min.y = min_3(c0.y, c1.y, c2.y);
	p.y = min.y < 0 ? 0 : min.y;
	z = -(c0.z + c1.z + c2.z) / 3;
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
						data.img.str[p.x + p.y * data.config.s_width] = 0;
						//data.img.str[p.x + p.y * data.config.s_width] = data.background_color;
				}
			}
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
			//printf("[%d][%d]\n", y, x);
			if (x < data.map_width - 1 && y < data.map_height - 1)
			{
				fill_ztriangle(new_fcoord3(data.moved_map[k].x, data.moved_map[k].y, data.rotated_map[k].z), new_fcoord3(data.moved_map[k + 1].x, data.moved_map[k + 1].y, data.rotated_map[k + 1].z), new_fcoord3(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y, data.rotated_map[k + data.map_width + 1].z), data);
				fill_ztriangle(new_fcoord3(data.moved_map[k].x, data.moved_map[k].y, data.rotated_map[k].z), new_fcoord3(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y, data.rotated_map[k + data.map_width + 1].z), new_fcoord3(data.moved_map[k + data.map_width].x, data.moved_map[k + data.map_width].y, data.rotated_map[k + data.map_width].z), data);
				if (data.config.centers == 2)
					plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width + 1].x, data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
			}
			if (x < data.map_width - 1)
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + 1].x, data.moved_map[k + 1].y), data, get_color(x, y, data));
			if (y < data.map_height - 1)
			{
				plot_line(new_coord2(data.moved_map[k].x, data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width].x, data.moved_map[k + data.map_width].y), data, get_color(x, y, data));
			}
			x++;
			k++;
		}
		y++;
	}
	flush_zbuffer(data);
}
