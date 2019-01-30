/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:33:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 18:45:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"

void	fill_img_z(t_coord2 c, t_env data, int color, t_fcoord3 vertices[3])
{
	float		z;
	t_fcoord3	w;

	/*if (data.norm == -1)
	  color = 0xFF0000;
	  else
	  color = 0x00FF00;*/
	if (data.config.debug == 1)
		color = 0xFFFFFF;
	if (c.x < 200 || c.x > data.config.s_width - 1 || c.y < 0 || c.y > data.config.s_height - 1)
		return ;
	//data.img.str[c.x + c.y * data.config.s_width] = color;
	w.x = edge(vertices[0], vertices[1], new_fcoord3(c.x, c.y, 0));
	w.y = edge(vertices[1], vertices[2], new_fcoord3(c.x, c.y, 0));
	w.z = edge(vertices[2], vertices[0], new_fcoord3(c.x, c.y, 0));
	w.x /= data.area;
	w.y /= data.area;
	w.z /= data.area;
	//z = -(w.x * vertices[2].z + w.y * vertices[0].z + w.z * vertices[1].z);
	z = -(vertices[2].z + w.y * data.c0_c2 + w.z * data.c1_c2);
	if (z <= data.zbuffer[c.x + c.y * data.config.s_width])
	{
		data.zbuffer[c.x + c.y * data.config.s_width] = z;
		data.img.str[c.x + c.y * data.config.s_width] = color;
	}
}

void	plot_line_low_z(t_coord2 c[2], t_env data, int color, t_fcoord3 vertices[3])
{
	int	dx;
	int	dy;
	int	yi;
	int	e;

	dy = c[1].y - c[0].y;
	dx = c[1].x - c[0].x;
	yi = dy < 0 ? -1 : 1;
	dy = ft_abs(dy);
	e = 2 * dy - dx;
	while (c[0].x <= c[1].x)
	{
		fill_img_z(c[0], data, color, vertices);
		c[0].y = e > 0 ? c[0].y + yi : c[0].y;
		e = e > 0 ? e - 2 * dx : e;
		e += 2 * dy;
		c[0].x++;
	}
}

void	plot_line_high_z(t_coord2 c[2], t_env data, int color, t_fcoord3 vertices[3])
{
	int	dx;
	int	dy;
	int	xi;
	int	e;

	dy = c[1].y - c[0].y;
	dx = c[1].x - c[0].x;
	xi = dx < 0 ? -1 : 1;
	dx = ft_abs(dx);
	e = 2 * dx - dy;
	while (c[0].y <= c[1].y)
	{
		fill_img_z(c[0], data, color, vertices);
		c[0].x = e > 0 ? c[0].x + xi : c[0].x;
		e = e > 0 ? e - 2 * dy : e;
		e += 2 * dx;
		c[0].y++;
	}
}

void	swap_tcoord2(t_coord2 c[2])
{
	t_coord2 tmp;

	tmp = new_coord2(c[0].x, c[0].y);
	c[0] = new_coord2(c[1].x, c[1].y);
	c[1] = new_coord2(tmp.x, tmp.y);
}

void	plot_line_z(t_coord2 c[2], t_env data, int color, t_fcoord3 vertices[3])
{
	if (ft_abs(c[1].y - c[0].y) < ft_abs(c[1].x - c[0].x))
		if (c[0].x > c[1].x)
		{
			swap_tcoord2(c);
			plot_line_low_z(c, data, color, vertices);
		}
		else
			plot_line_low_z(c, data, color, vertices);
	else
	{
		if (c[0].y > c[1].y)
		{
			swap_tcoord2(c);
			plot_line_high_z(c, data, color, vertices);
		}
		else
			plot_line_high_z(c, data, color, vertices);
	}
}
