/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:40:57 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/06 11:47:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "mlx_keycode.h"

int		expose(void *param)
{
	(void)param;
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	ft_putendl("CLOSE");
	exit(0);
}
