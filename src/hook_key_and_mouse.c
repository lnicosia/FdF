/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/03 15:14:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "user_functions.h"
#include "mlx_keycode.h"
#include <stdio.h>

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
		data->angle.x += 0.15707963267;
		process_all(data);
	}
	else if (key == NK2_KEY)
	{
		data->angle.x -= 0.15707963267;
		process_all(data);
	}
	else if (key == NK4_KEY)
	{
		data->angle.y += 0.15707963267;
		process_all(data);
	}
	else if (key == NK5_KEY)
	{
		data->angle.y -= 0.15707963267;
		process_all(data);
	}
	else if (key == NK7_KEY)
	{
		data->angle.z += 0.15707963267;
		process_all(data);
	}
	else if (key == NK8_KEY)
	{
		data->angle.z -= 0.15707963267;
		process_all(data);
	}
	else if (key == C_KEY)
	{
		data->color = data->color == 1 ? 0 : 1;
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
	{
		//printf("[%d][%d]\n", x, y);
		zoom_in(data, x, y);
	}
	else if (button == SCROLLDOWN_KEY)
	{
		//printf("[%d][%d]\n", x, y);
		zoom_out(data, x, y);
	}
	else if (button == BUT1_KEY)
	{
		data->button1_state = 1;
		data->drag_start.x = x;
		data->drag_start.y = y;
	}
	else if (button == BUT2_KEY)
	{
		//printf("Start: [%d][%d]\n", x, y);
	}
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	(void)x;
	(void)y;
	if (button == BUT1_KEY)
	{
		data->button1_state = 0;
	}
	else if (button == BUT2_KEY)
	{
		//printf("Start: [%d][%d]\n", x, y);
	}
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_env	*data;

	(void)x;
	(void)y;
	data = (t_env*)param;
	if (data->button1_state == 1)
	{
		data->angle.x += 0.00314159265 * (y - data->drag_start.y);
		data->angle.z -= 0.00314159265 * (x - data->drag_start.x);
		process_all(data);
		data->drag_start.x = x;
		data->drag_start.y = y;
	}
	return (0);
}
