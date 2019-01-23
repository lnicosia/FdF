/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:23:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 11:50:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_coord2	new_coord2(int x, int y)
{
	t_coord2 c;

	c.x = x;
	c.y = y;
	return (c);
}

t_coord3	new_coord3(int x, int y, int z)
{
	t_coord3 c;

	c.x = x;
	c.y = y;
	c.z = z;
	return (c);
}

t_fcoord3	new_fcoord3(float x, float y, float z)
{
	t_fcoord3 c;

	c.x = x;
	c.y = y;
	c.z = z;
	return (c);
}
