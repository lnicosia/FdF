/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_poly_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 11:38:32 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 12:26:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		min_3(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b < c)
			return (b);
		else
			return (c);
	}
}

int		max_3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (a);
		else
			return (c);
	}
	else
	{
		if (b > c)
			return (b);
		else
			return (c);
	}
}

int		bottom_vertex(float a, float b, float c, float d)
{
	float	tab[3];
	float	res;
	int		index;
	int		i;

	tab[0] = b;
	tab[1] = c;
	tab[2] = d;
	res = a;
	i = 0;
	index = 0;
	while (i < 3)
	{
		if (res > tab[i])
		{
			res = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		top_vertex(float a, float b, float c, float d)
{
	float	tab[3];
	float	res;
	int		index;
	int		i;

	tab[0] = b;
	tab[1] = c;
	tab[2] = d;
	res = a;
	i = 0;
	index = 0;
	while (i < 3)
	{
		if (res < tab[i])
		{
			res = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

float	edge(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 p)
{
	return ((p.x - c0.x) * (c1.y - c0.y) - (p.y - c0.y) * (c1.x - c0.x));
}
