/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:40:57 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 11:09:10 by lnicosia         ###   ########.fr       */
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
	t_env *data;

	data = (t_env*)param;
	ft_putendl("CLOSE");
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}
