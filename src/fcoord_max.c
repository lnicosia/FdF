/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcoord_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 12:15:48 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 15:54:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

float	fmin3(t_fcoord3 *map, int size, char mode)
{
	float	res;
	float	tmp;
	int		i;

	if (mode != 'x' && mode != 'y' && mode != 'z')
	{
		put_log("fmin3: invalid mode.", 1);
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

float	fmax3(t_fcoord3 *map, int size, char mode)
{
	float	res;
	float	tmp;
	int		i;

	if (mode != 'x' && mode != 'y' && mode != 'z')
	{
		put_log("fmax3: invalid mode.", 1);
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
