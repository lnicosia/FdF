/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:33:53 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/04 17:57:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"

int		plotLineLow(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	yi;
	float e;

	dy = y2 - y1;
	dx = x2 - x1;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	e = 2 * dy - dx;
	while (x1 <= x2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
		if (e > 0)
		{
			y1 += yi;
			e -= 2 * dx;
		}
		e += 2 * dy;
		x1++;
	}
	return (0);
};

int		plotLineHigh(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
	int	dx;
	int	dy;
	int	xi;
	float e;

	dy = y2 - y1;
	dx = x2 - x1;
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	e = 2 * dx - dy;
	while (y1 <= y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x1, y1, 0xFFFFFF);
		if (e > 0)
		{
			x1 += xi;
			e -= 2 * dy;
		}
		e += 2 * dx;
		y1++;
	}
	return (0);
};

int		plotLine(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr)
{
	if (ft_abs(y2 - y1) < ft_abs(x2 - x1))
		if (x1 > x2)
			plotLineLow(x2, y2, x1, y1, mlx_ptr, win_ptr);
		else
			plotLineLow(x1, y1, x2, y2, mlx_ptr, win_ptr);
	else
		if (y1 > y2)
			plotLineHigh(x2, y2, x1, y1, mlx_ptr, win_ptr);
		else
			plotLineHigh(x1, y1, x2, y2, mlx_ptr, win_ptr);
	return (0);
}
