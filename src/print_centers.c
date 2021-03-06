/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle_of_faces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:48:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 15:11:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		middle_of_face(int k, unsigned int color, t_env data)
{
	t_coord2 c;

	c = new_coord2((data.moved_map[k + data.map_width + 1].x +
	data.moved_map[k].x + data.moved_map[k + 1].x + data.moved_map[k +
	data.map_width].x) / 4, (data.moved_map[k + data.map_width + 1].y +
	data.moved_map[k].y + data.moved_map[k + 1].y + data.moved_map[k +
	data.map_width].y) / 4);
	if (c.x >= 0 && c.x < data.config.s_width && c.y >= 0 && c.y <
			data.config.s_height)
		data.img.str[c.x + c.y * data.config.s_width] = color;
}

void		print_centers(t_env data)
{
	int	x;
	int	y;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1 && y < data.map_height - 1)
			{
				if (data.config.centers == 1)
					middle_of_face(k, get_color(x, y, data), data);
				if (data.config.centers == 2)
					plot_line(new_coord2(data.moved_map[k].x,
data.moved_map[k].y), new_coord2(data.moved_map[k + data.map_width + 1].x,
	data.moved_map[k + data.map_width + 1].y), data, get_color(x, y, data));
			}
			x++;
			k++;
		}
		y++;
	}
}
