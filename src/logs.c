/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:04:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 14:57:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "color.h"
#include "utils.h"

void	put_log(const char *str, int mode)
{
	if (mode == 0)
		ft_putstr(GREEN);
	else
		ft_putstr(RED);
	ft_putstr(str);
	ft_putendl(RESET);
}

void	put_map_size(int height, int width)
{
	ft_putnbr(width);
	ft_putstr(" x ");
	ft_putnbr(height);
	ft_putchar('\n');
}
