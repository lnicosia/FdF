/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 11:43:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "mlx_keycode.h"

int		key_press(int key, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (key == ESC_KEY)
	{
		ft_putendl("ESCAPE");
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		while (1)
		{
		}
		exit(0);
	}
	else
		ft_putendl("Coucou");
	return (0);
}

int		key_release(int key, void *param)
{
	(void)key;
	(void)param;
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	(void)button;
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	(void)button;
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
