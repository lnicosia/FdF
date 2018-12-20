/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:25:30 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/20 17:28:03 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

void	global_x_rotation(t_env data)
{
	float	tmp;
	int		y;
	int		x;
	int		k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.map[k].y;
			data.map[k].y = data.map[k].y * cos(data.angle.x) + data.map[k].z * sin(data.angle.x);
			data.map[k].z = -tmp * sin(data.angle.x) + data.map[k].z * cos(data.angle.x);
			x++;
			k++;
		}
		y++;
	}
}

void	global_y_rotation(t_env data)
{
	float	tmp;
	int		y;
	int		x;
	int		k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.map[k].x;
			data.map[k].x = data.map[k].x * cos(data.angle.y) + data.map[k].z * sin(data.angle.y);
			data.map[k].z = -tmp * sin(data.angle.y) + data.map[k].z * cos(data.angle.y);
			x++;
			k++;
		}
		y++;
	}
}

void	global_z_rotation(t_env data)
{
	float	tmp;
	int		y;
	int		x;
	int		k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.map[k].x;
			data.map[k].x = data.map[k].x * cos(data.angle.z) - data.map[k].y * sin(data.angle.z);
			data.map[k].y = tmp * sin(data.angle.z) + data.map[k].y * cos(data.angle.z);
			x++;
			k++;
		}
		y++;
	}
}
