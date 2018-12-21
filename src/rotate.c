/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:50:51 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/21 15:40:50 by lnicosia         ###   ########.fr       */
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
			data.rotated_map[k].y = (float)data.map[k].y * cos(data.angle.x) + (float)data.map[k].z * data.scale.z * sin(data.angle.x);
			data.rotated_map[k].z = -(float)data.map[k].y * sin(data.angle.x) + (float)data.map[k].z * data.scale.z * cos(data.angle.x);
			data.rotated_map[k].x = (float)data.map[k].x;
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
	float	tmp;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.rotated_map[k].x;
			data.rotated_map[k].x = data.rotated_map[k].x * cos(data.angle.y) + data.rotated_map[k].z * sin(data.angle.y);
			data.rotated_map[k].z = -tmp * sin(data.angle.y) + data.rotated_map[k].z  * cos(data.angle.y);
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
	float	tmp;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.rotated_map[k].x;
			data.rotated_map[k].x = data.rotated_map[k].x * cos(data.angle.z) - data.rotated_map[k].y * sin(data.angle.z);
			data.rotated_map[k].y = tmp * sin(data.angle.z) + data.rotated_map[k].y * cos(data.angle.z);
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


void	float_map(t_env data)
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
			data.rotated_map[k].x = (float)data.map[k].x;
			data.rotated_map[k].y = (float)data.map[k].y;
			data.rotated_map[k].z = (float)data.map[k].z * data.scale.z;
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

void	rotate(t_env data)
{
	x_rotation(data);
	y_rotation(data);
	z_rotation(data);
}
