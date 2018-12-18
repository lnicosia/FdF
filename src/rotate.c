/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:50:51 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/18 15:44:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "utils.h"

void	x_rotation(t_coord3 *c, t_env data)
{
	int	tmp;

	tmp = c->y;
	c->y = c->y * cos(data.angle.x) + c->z * sin(data.angle.x);
	c->z = -tmp * sin(data.angle.x) + c->z * cos(data.angle.x);
}

void	y_rotation(t_coord3 *c, t_env data)
{
	int	tmp;

	tmp = c->x;
	c->x = c->x * cos(data.angle.y) + c->z * sin(data.angle.y);
	c->z = -tmp * sin(data.angle.y) + c->z * cos(data.angle.y);
}

void	z_rotation(t_coord3 *c, t_env data)
{
	int	tmp;

	tmp = c->x;
	c->x = c->x * cos(data.angle.z) - c->y * sin(data.angle.z);
	c->y = tmp * sin(data.angle.z) + c->y * cos(data.angle.z);
}
