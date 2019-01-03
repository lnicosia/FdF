/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 11:00:36 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/03 14:52:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(char *nbr, char *base_from)
{
	int res;
	int j;
	int k;
	int neg;

	neg = 1;
	res = 0;
	k = 0;
	if (*nbr == '-')
	{
		neg = -1;
		nbr++;
	}
	while (*nbr && *nbr != ' ')
	{
		j = -1;
		while (base_from[++j])
		{
			if (*nbr == base_from[j])
				res = ft_strlen(base_from) * res + j;
		}
		nbr++;
		k++;
	}
	return (res * neg);
}
