/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:33:53 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/14 17:42:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"

static void	fill_img(t_coord2 c, t_env data, int color)
{
	if (c.x < 0 || c.x > data.s_width || c.y < 0 || c.y > data.s_height)
		return ;
	if (c.x + c.y * data.s_width < data.s_height * data.s_width - 1 && c.x +
			c.y * data.s_width >= 0)
		data.img.str[c.x + c.y * data.s_width] = color;
}

static int	plot_line_low(t_coord2 c1, t_coord2 c2, t_env data, int color)
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
		fill_img(c1, data, color);
		c1.y = e > 0 ? c1.y + yi : c1.y;
		e = e > 0 ? e - 2 * dx : e;
		e += 2 * dy;
		c1.x++;
	}
	return (0);
}

static int	plot_line_high(t_coord2 c1, t_coord2 c2, t_env data, int color)
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
		fill_img(c1, data, color);
		c1.x = e > 0 ? c1.x + xi : c1.x;
		e = e > 0 ? e - 2 * dy : e;
		e += 2 * dx;
		c1.y++;
	}
	return (0);
}

int			plot_line(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	if (ft_abs(c2.y - c1.y) < ft_abs(c2.x - c1.x))
		if (c1.x > c2.x)
			plot_line_low(c2, c1, data, color);
		else
			plot_line_low(c1, c2, data, color);
	else
	{
		if (c1.y > c2.y)
			plot_line_high(c2, c1, data, color);
		else
			plot_line_high(c1, c2, data, color);
	}
	return (0);
}