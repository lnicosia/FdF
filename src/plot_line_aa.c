/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line_aa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:42:59 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 15:51:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include <stdio.h>

int		ipart(int x)
{
	return ((int)x);
}

int		round_(int x)
{
	return ((int)(((double)x) + 0.5));
}

float	fpart(float x)
{
	return (((double)x) - (double)ipart(x));
}

float	rfpart(float x)
{
	return (1.0 - fpart(x));
}

void	plot_line_low_aa(t_coord2 c1, t_coord2 c2, t_env data, int color)
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
	fill_img(new_coord2(xpx11, ypx11), data, color, rfpart(yend) * xgap);
	fill_img(new_coord2(xpx11, ypx11 + 1), data, color, fpart(yend) * xgap);
	intery = yend + gradient;
	xend = round_(c2.x);
	yend = c2.y + gradient * (xend - c2.x);
	xgap = fpart(c2.x + 0.5);
	xpx12 = xend;
	ypx12 = ipart(yend);
	fill_img(new_coord2(xpx12, ypx12), data, color, rfpart(yend) * xgap);
	fill_img(new_coord2(xpx12, ypx12 + 1), data, color, fpart(yend) * xgap);
	while (xpx11 < xpx12)
	{
		fill_img(new_coord2(xpx11, ipart(intery)), data, color,
				rfpart(intery));
		fill_img(new_coord2(xpx11, ipart(intery) + 1), data, color,
				fpart(intery));
		xpx11++;
		intery += gradient;
	}
}

void	plot_line_high_aa(t_coord2 c1, t_coord2 c2, t_env data, int color)
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
	fill_img(new_coord2(xpx11, ypx11), data, color, rfpart(xend) * ygap);
	fill_img(new_coord2(xpx11 + 1, ypx11), data, color, fpart(xend) * ygap);
	intery = xend + gradient;
	yend = round_(c2.y);
	xend = c2.x + gradient * (yend - c2.y);
	ygap = fpart(c2.y + 0.5);
	ypx12 = yend;
	xpx12 = ipart(xend);
	fill_img(new_coord2(xpx12, ypx12), data, color, rfpart(xend) * ygap);
	fill_img(new_coord2(xpx12 + 1, ypx12), data, color, fpart(xend) * ygap);
	while (ypx11 < ypx12)
	{
		fill_img(new_coord2(ipart(intery), ypx11), data, color,
				rfpart(intery));
		fill_img(new_coord2(ipart(intery) + 1, ypx11), data, color,
				fpart(intery));
		ypx11++;
		intery += gradient;
	}
}
