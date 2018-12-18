/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/18 15:43:09 by lnicosia         ###   ########.fr       */
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
	else if (key == P_KEY)
		swap_project_type(data);
	else if (key == PUP_KEY)
		increase_color_div(data);
	else if (key == PDOWN_KEY)
		decrease_color_div(data);
	else if (key == NK1_KEY)
	{
		data->angle.x += 0.1;
		redraw(data);
	}
	else if (key == NK2_KEY)
	{
		data->angle.x -= 0.1;
		redraw(data);
	}
	else if (key == NK4_KEY)
	{
		data->angle.y += 0.1;
		redraw(data);
	}
	else if (key == NK5_KEY)
	{
		data->angle.y -= 0.1;
		redraw(data);
	}
	else if (key == NK7_KEY)
	{
		data->angle.z += 0.1;
		redraw(data);
	}
	else if (key == NK8_KEY)
	{
		data->angle.z -= 0.1;
		redraw(data);
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
