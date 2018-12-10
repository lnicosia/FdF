/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:45:55 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 16:00:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include <stdio.h>

static void	iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -(z) + (previous_x + previous_y) * sin(0.523599);
}

void		trace(t_env data, t_img img)
{
	float		x_scale;
	float		y_scale;
	int			x;
	int			y;
	t_coord2	c1;
	t_coord2	c2;
	t_coord2	c3;

	x_scale = data.s_width / data.map_width;
	y_scale = data.s_width / data.map_width;
	ft_putstr("x_scale: "); printf("%f\n", x_scale);
	ft_putstr("y_scale: "); printf("%f\n", y_scale);
	y = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			c1 = new_coord2(x * x_scale, y * y_scale);
			c2 = new_coord2((x + 1) * x_scale, y * y_scale);
			c3 = new_coord2(x * x_scale, (y + 1) * y_scale);
			iso(&c1.x, &c1.y, data.map[y][x]);
			//c1.x += data.s_width * 30 / 100;
			if (x < data.map_width - 1)
			{
				iso(&c2.x, &c2.y, data.map[y][x + 1]);
				//c2.x += data.s_width * 30 / 100;
				plot_line(new_coord2(c1.x, c1.y), new_coord2(c2.x, c2.y), img);
			}
			if (y < data.map_height - 1)
			{
				iso(&c3.x, &c3.y, data.map[y + 1][x]);
				//c3.x += data.s_width * 30 / 100;
				plot_line(new_coord2(c1.x, c1.y), new_coord2(c3.x, c3.y), img);
			}
			x++;
		}
		y++;
	}
}
