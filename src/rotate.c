/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:50:51 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/21 12:44:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"
#include <stdio.h>

void	x_rotation(t_env data)
{
	int	y;
	int	x;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			data.processed_map[k].y = (float)data.map[k].y * cos(data.angle.x) + (float)data.map[k].z * sin(data.angle.x);
			data.processed_map[k].z = -(float)data.map[k].y * sin(data.angle.x) + (float)data.map[k].z * cos(data.angle.x);
			x++;
			k++;
		}
		y++;
	}
}

void	y_rotation(t_env data)
{
	int	y;
	int	x;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			data.processed_map[k].x = (float)data.map[k].x * cos(data.angle.y) + (float)data.map[k].z * sin(data.angle.y);
			data.processed_map[k].z = -(float)data.map[k].x * sin(data.angle.y) + (float)data.map[k].z * cos(data.angle.y);
			x++;
			k++;
		}
		y++;
	}
	/*float	tmp;

	tmp = c->x;
	c->x = c->x * cos(data.angle.y) + c->z * sin(data.angle.y);
	c->z = -tmp * sin(data.angle.y) + c->z * cos(data.angle.y);*/
}

void	z_rotation(t_env data)
{
	int	y;
	int	x;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			data.processed_map[k].x = (float)data.map[k].x * cos(data.angle.z) - (float)data.map[k].y * sin(data.angle.z);
			data.processed_map[k].y = -(float)data.map[k].x * sin(data.angle.z) + (float)data.map[k].y * cos(data.angle.z);
			x++;
			k++;
		}
		y++;
	}
	/*float	tmp;

	tmp = c->x;
	c->x = c->x * cos(data.angle.z) - c->y * sin(data.angle.z);
	c->y = tmp * sin(data.angle.z) + c->y * cos(data.angle.z);*/
}
