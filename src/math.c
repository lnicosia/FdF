/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:46:30 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 16:48:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ipart(int x)
{
	return ((int)x);
}

int		round_(int x)
{
	return ((int)(((double)x) + 0.5));
}

float	fpart(float x)
{
	return (((double)x) - (double)ipart(x));
}

float	rfpart(float x)
{
	return (1.0 - fpart(x));
}
