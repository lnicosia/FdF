/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:04:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 14:07:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "color.h"

void	put_log(const char *str, int mode)
{
	if (mode == 0)
		ft_putstr(GREEN);
	else
		ft_putstr(RED);
	ft_putstr(str);
	ft_putendl(RESET);
}
