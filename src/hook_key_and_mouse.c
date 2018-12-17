/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 15:55:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "user_functions.h"
#include "mlx_keycode.h"

int		key_press(int key, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (key == ESC_KEY)
		quit(data);
	else if (key == NKPL_KEY)
		increase_z(data);
	else if (key == NKMN_KEY)
		decrease_z(data);
	else if (key == UP_KEY)
		move_up(data);
	else if (key == DOWN_KEY)
		move_down(data);
	else if (key == RIGHT_KEY)
		move_right(data);
	else if (key == LEFT_KEY)
		move_left(data);
	else if (key == A_KEY)
		swap_trace_type(data);
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
	t_env	*data;

	data = (t_env*)param;
	if (button == SCROLLUP_KEY)
		zoom_in(data);
	else if (button == SCROLLDOWN_KEY)
		zoom_out(data);
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
