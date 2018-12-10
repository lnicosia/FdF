/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 12:27:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include <stdio.h>

void	trace(t_env data, t_img img)
{
	float	x_scale;
	float	y_scale;
	int		x_start;
	int		y_start;
	int		x_end;
	int		y_end;
	int		x;
	int		y;

	(void)img;
	
	x_start = data.s_width * 10 / 200;
	y_start = data.s_height * 10 / 200;
	x_end = data.s_width - x_start;
	y_end = data.s_height - y_start;
	x_scale = (data.s_width - x_start) / data.map_width;
	y_scale = (data.s_height - y_start) / data.map_height;
	ft_putstr("x_start: "); printf("%d\n", x_start);
	ft_putstr("y_start: "); printf("%d\n", y_start);
	ft_putstr("x_end: "); printf("%d\n", x_end);
	ft_putstr("y_end: "); printf("%d\n", y_end);
	ft_putstr("x_scale: "); printf("%f\n", x_scale);
	ft_putstr("y_scale: "); printf("%f\n", y_scale);

	y = y_start;
	while (y <= y_end)
	{
		x = x_start;
		while (x <= x_end)
		{
			if (x != x_end)
			plot_line(new_coord2(x, y), new_coord2(x + x_scale, y), img);
			if (y < y_end - y_scale)
				plot_line(new_coord2(x, y), new_coord2(x, y + y_scale), img);
			x += x_scale;
		}
		y += y_scale;
	}
}
