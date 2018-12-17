/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:42:59 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 13:55:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include <stdio.h>

int			ipart(int x)
{
	return ((int)x);
}

int			round_(int x)
{
	return ((int)(((double)x) + 0.5));
}

float		fpart(float x)
{
	return (((double)x) - (double)ipart(x));
}

float		rfpart(float x)
{
	return (1.0 - fpart(x));
}

void		fill_img_aa(t_coord2 c, t_env data, int color, float brightness)
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
		/*printf("Color = %08X\n", color);
		printf("R = %08X	G = %08X	B = %08X\n", red, green, blue);
		printf("R = %d		G = %d		B = %d\n", red, green, blue);*/
		red = red * brightness;
		blue = blue * brightness;
		green = green * brightness;
		/*printf("R = %08X	G = %08X	B = %08X\n", red, green, blue);
		printf("R = %d		G = %d		B = %d\n", red, green, blue);*/
		/*printf("[%d][%d]\n[brightness] = %f [base_color] = %d
		 * [new color] = %d\n", c.x, c.y, brightness, color, ((red << 16 )
		 * | (green << 8) | blue));*/
		data.img.str[c.x + c.y * data.s_width] = ((red << 16) | (green << 8)
				| blue);
	}
}

static int	plot_line_low_aa(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	float	dx;
	float	dy;
	int		xpx11;
	int		ypx11;
	int		xpx12;
	int		ypx12;
	float	xend;
	float	yend;
	float	intery;
	float	gradient;
	float	xgap;

	dy = c2.y - c1.y;
	dx = c2.x - c1.x;
	if (dx == 0)
		gradient = 1.0;
	else
		gradient = dy / dx;
	xend = round_(c1.x);
	yend = c1.y + gradient * (xend - c1.x);
	xgap = rfpart(c1.x + 0.5);
	xpx11 = xend;
	ypx11 = ipart(yend);
	fill_img_aa(new_coord2(xpx11, ypx11), data, color, rfpart(yend) * xgap);
	fill_img_aa(new_coord2(xpx11, ypx11 + 1), data, color, fpart(yend) * xgap);
	intery = yend + gradient;
	xend = round_(c2.x);
	yend = c2.y + gradient * (xend - c2.x);
	xgap = fpart(c2.x + 0.5);
	xpx12 = xend;
	ypx12 = ipart(yend);
	fill_img_aa(new_coord2(xpx12, ypx12), data, color, rfpart(yend) * xgap);
	fill_img_aa(new_coord2(xpx12, ypx12 + 1), data, color, fpart(yend) * xgap);
	while (xpx11 < xpx12)
	{
		fill_img_aa(new_coord2(xpx11, ipart(intery)), data, color,
				rfpart(intery));
		fill_img_aa(new_coord2(xpx11, ipart(intery) + 1), data, color,
				fpart(intery));
		xpx11++;
		intery += gradient;
	}
	return (0);
}

static int	plot_line_high_aa(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	float	dx;
	float	dy;
	int		xpx11;
	int		ypx11;
	int		xpx12;
	int		ypx12;
	float	xend;
	float	yend;
	float	intery;
	float	gradient;
	float	ygap;

	dy = c2.y - c1.y;
	dx = c2.x - c1.x;
	if (dy == 0)
		gradient = 1.0;
	else
		gradient = dx / dy;
	yend = round_(c1.y);
	xend = c1.x + gradient * (yend - c1.y);
	ygap = rfpart(c1.y + 0.5);
	ypx11 = yend;
	xpx11 = ipart(xend);
	fill_img_aa(new_coord2(xpx11, ypx11), data, color, rfpart(xend) * ygap);
	fill_img_aa(new_coord2(xpx11 + 1, ypx11), data, color, fpart(xend) * ygap);
	intery = xend + gradient;
	yend = round_(c2.y);
	xend = c2.x + gradient * (yend - c2.y);
	ygap = fpart(c2.y + 0.5);
	ypx12 = yend;
	xpx12 = ipart(xend);
	fill_img_aa(new_coord2(xpx12, ypx12), data, color, rfpart(xend) * ygap);
	fill_img_aa(new_coord2(xpx12 + 1, ypx12), data, color, fpart(xend) * ygap);
	while (ypx11 < ypx12)
	{
		fill_img_aa(new_coord2(ipart(intery), ypx11), data, color,
				rfpart(intery));
		fill_img_aa(new_coord2(ipart(intery) + 1, ypx11), data, color,
				fpart(intery));
		ypx11++;
		intery += gradient;
	}
	return (0);
}

int			plot_line_aa(t_coord2 c1, t_coord2 c2, t_env data, int color)
{
	if (ft_abs(c2.y - c1.y) < ft_abs(c2.x - c1.x))
		if (c1.x > c2.x)
			plot_line_low_aa(c2, c1, data, color);
		else
			plot_line_low_aa(c1, c2, data, color);
	else
	{
		if (c1.y > c2.y)
			plot_line_high_aa(c2, c1, data, color);
		else
			plot_line_high_aa(c1, c2, data, color);
	}
	return (0);
}
