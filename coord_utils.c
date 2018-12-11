/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:23:59 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 10:49:04 by lnicosia         ###   ########.fr       */
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

int			min3(t_coord3 *map, int size, char mode)
{
	int	res;
	int	tmp;
	int	i;

	if (mode != 'x' && mode != 'y' && mode != 'z')
	{
		ft_putendl("min3: invalid mode.");
		return (0);
	}
	i = -1;
	res = mode == 'x' ? map[0].x : 0;
	res = mode == 'y' ? map[0].y : 0;
	res = mode == 'z' ? map[0].z : 0;
	while (++i < size)
	{
		if (mode == 'x')
			tmp = map[i].x;
		else if (mode == 'y')
			tmp = map[i].y;
		else if (mode == 'z')
			tmp = map[i].z;
		res = res > tmp ? tmp : res;
	}
	return (res);
}

int			max3(t_coord3 *map, int size, char mode)
{
	int	res;
	int	tmp;
	int	i;

	if (mode != 'x' && mode != 'y' && mode != 'z')
	{
		ft_putendl("max3: invalid mode.");
		return (0);
	}
	i = -1;
	res = mode == 'x' ? map[0].x : 0;
	res = mode == 'y' ? map[0].y : 0;
	res = mode == 'z' ? map[0].z : 0;
	while (++i < size)
	{
		if (mode == 'x')
			tmp = map[i].x;
		else if (mode == 'y')
			tmp = map[i].y;
		else if (mode == 'z')
			tmp = map[i].z;
		res = res < tmp ? tmp : res;
	}
	return (res);
}
