/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:40:57 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/14 16:14:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "user_functions.h"
#include "color.h"

int		expose(void *param)
{
	(void)param;
	return (0);
}

int		close_window(void *param)
{
	t_env *data;

	data = (t_env*)param;
	ft_putstr(RED);
	ft_putstr("[CLOSE]");
	ft_putendl(RESET);
	quit(data);
	return (0);
}
