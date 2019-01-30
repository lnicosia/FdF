/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:49:59 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 16:11:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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

int			cmin3(t_coord3 *map, int size, char mode)
{
	int	res;
	int	tmp;
	int	i;
	int	k;

	if (mode != 'x' && mode != 'y' && mode != 'z')
	{
		ft_putendl("min3: invalid mode.");
		return (0);
	}
	k = 0;
	i = -1;
	res = mode == 'x' ? map[0].x : 0;
	res = mode == 'y' ? map[0].y : 0;
	res = mode == 'z' ? map[0].z : 0;
	while (++i < size)
	{
		tmp = mode == 'x' ? map[i].x : tmp;
		tmp = mode == 'y' ? map[i].y : tmp;
		tmp = mode == 'z' ? map[i].z : tmp;
		k = res > tmp ? i : k;
		res = res > tmp ? tmp : res;
	}
	return (k);
}

int			cmax3(t_coord3 *map, int size, char mode)
{
	int	res;
	int	tmp;
	int	i;
	int	k;

	if (mode != 'x' && mode != 'y' && mode != 'z')
	{
		ft_putendl("max3: invalid mode.");
		return (0);
	}
	k = 0;
	i = -1;
	res = mode == 'x' ? map[0].x : 0;
	res = mode == 'y' ? map[0].y : 0;
	res = mode == 'z' ? map[0].z : 0;
	while (++i < size)
	{
		tmp = mode == 'x' ? map[i].x : tmp;
		tmp = mode == 'y' ? map[i].y : tmp;
		tmp = mode == 'z' ? map[i].z : tmp;
		k = res < tmp ? i : k;
		res = res < tmp ? tmp : res;
	}
	return (k);
}
