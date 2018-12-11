/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:33:53 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 14:07:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"

static void	fill_img(t_coord2 c, t_img img, t_env data)
{
	(void)data;
	if (c.x * (img.bit_per_pixels / 8) + c.y * img.size_line + 3
			< data.s_height * data.s_width * img.bit_per_pixels)
	{
		img.str[c.x * (img.bit_per_pixels / 8) +
			c.y * img.size_line] = 0xFF;
		img.str[c.x * (img.bit_per_pixels / 8) +
			c.y * img.size_line + 1] = 0xFF;
		img.str[c.x * (img.bit_per_pixels / 8) +
			c.y * img.size_line + 2] = 0xFF;
	}
}

static int	plot_line_low(t_coord2 c1, t_coord2 c2, t_img img, t_env data)
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
		fill_img(c1, img, data);
		c1.y = e > 0 ? c1.y + yi : c1.y;
		e = e > 0 ? e - 2 * dx : e;
		e += 2 * dy;
		c1.x++;
	}
	return (0);
}

static int	plot_line_high(t_coord2 c1, t_coord2 c2, t_img img, t_env data)
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
		fill_img(c1, img, data);
		c1.x = e > 0 ? c1.x + xi : c1.x;
		e = e > 0 ? e - 2 * dy : e;
		e += 2 * dx;
		c1.y++;
	}
	return (0);
}

int			plot_line(t_coord2 c1, t_coord2 c2, t_img img, t_env data)
{
	if (ft_abs(c2.y - c1.y) < ft_abs(c2.x - c1.x))
		if (c1.x > c2.x)
			plot_line_low(c2, c1, img, data);
		else
			plot_line_low(c1, c2, img, data);
	else
	{
		if (c1.y > c2.y)
			plot_line_high(c2, c1, img, data);
		else
			plot_line_high(c1, c2, img, data);
	}
	return (0);
}
