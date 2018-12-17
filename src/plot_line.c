/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:33:53 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 16:00:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"

void	fill_img(t_coord2 c, t_env data, int color, float brightness)
{
	int	red;
	int	green;
	int blue;

	if (c.x < 0 || c.x > data.s_width || c.y < 0 || c.y > data.s_height)
		return ;
	if (c.x + c.y * data.s_width < data.s_height * data.s_width - 1 && c.x +
			c.y * data.s_width >= 0)
	{
		red = color >> 16 & 0xFF;
		green = color >> 8 & 0xFF;
		blue = color & 0xFF;
		red = red * brightness;
		blue = blue * brightness;
		green = green * brightness;
		data.img.str[c.x + c.y * data.s_width] = ((red << 16) | (green << 8)
				| blue);
	}
}

void	plot_line_low(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	e;

	dy = c2.y - c1.y;
	dx = c2.x - c1.x;
	yi = dy < 0 ? -1 : 1;
	dy = ft_abs(dy);
	e = 2 * dy - dx;
	while (c1.x <= c2.x)
	{
		fill_img(c1, data, color, 1);
		c1.y = e > 0 ? c1.y + yi : c1.y;
		e = e > 0 ? e - 2 * dx : e;
		e += 2 * dy;
		c1.x++;
	}
}

void	plot_line_high(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	e;

	dy = c2.y - c1.y;
	dx = c2.x - c1.x;
	xi = dx < 0 ? -1 : 1;
	dx = ft_abs(dx);
	e = 2 * dx - dy;
	while (c1.y <= c2.y)
	{
		fill_img(c1, data, color, 1);
		c1.x = e > 0 ? c1.x + xi : c1.x;
		e = e > 0 ? e - 2 * dy : e;
		e += 2 * dx;
		c1.y++;
	}
}

void	plot_line(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	if (ft_abs(c2.y - c1.y) < ft_abs(c2.x - c1.x))
		if (c1.x > c2.x)
			data.plot_line_low[data.trace_type](c2, c1, data, color);
		else
			data.plot_line_low[data.trace_type](c1, c2, data, color);
	else
	{
		if (c1.y > c2.y)
			data.plot_line_high[data.trace_type](c2, c1, data, color);
		else
			data.plot_line_high[data.trace_type](c1, c2, data, color);
	}
}
