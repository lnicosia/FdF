/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:30:01 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/24 14:55:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"
#include "mlx_keycode.h"

int		key_press3(int key, t_env *data)
{
	if (key == C_KEY)
	{
		data->config.color++;
		if (data->config.color > 2)
			data->config.color = 0;
		data->input_buffers.color_button = 1;
	}
	else if (key == M_KEY)
	{
		data->config.centers++;
		if (data->config.centers > 2)
			data->config.centers = 0;
		data->input_buffers.centers_button = 1;
	}
	else if (key == B_KEY)
	{
		data->config.black_white = data->config.black_white == 1 ? 0 : 1;
		data->centers_color = data->config.black_white == 1 ? 0 : 0xFFFFFF;
		data->background_color = data->config.black_white == 1 ? 0xFFFFFF :
			0x404040;
	}
	redraw(data);
	return (0);
}

int		key_press2(int key, t_env *data)
{
	if (key == NK4_KEY)
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
	return (key_press3(key, data));
}

int		key_press1(int key, t_env *data)
{
	if (key == K3_KEY)
		swap_project_type(data, FLAT);
	else if (key == K4_KEY)
		swap_project_type(data, PC);
	else if (key == PT_KEY)
	{
		data->input_buffers.decrease_color = 1;
		decrease_color_div(data);
	}
	else if (key == CM_KEY)
	{
		data->input_buffers.increase_color = 1;
		increase_color_div(data);
	}
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
	return (key_press2(key, data));
}

int		key_press0(int key, t_env *data)
{
	if (key == A_KEY)
		data->input_buffers.a = 1;
	else if (key == T_KEY)
		data->config.trace = data->config.trace == 0 ? 1 : 0;
	else if (key == D_KEY)
		data->config.debug = data->config.debug == 1 ? 0 : 1;
	else if (key == P_KEY)
	{
		data->config.poly++;
		if (data->config.poly > 2)
			data->config.poly = 0;
	}
	else if (key == F_KEY)
		data->config.fill = data->config.fill == 0 ? 1 : 0;
	else if (key == E_KEY)
		data->edges_color = data->edges_color == 0xFFFFFF ? 0 : 0xFFFFFF;
	else if (key == L_KEY)
		data->config.light = data->config.light == 0 ? 1 : 0;
	else if (key == K1_KEY)
		swap_project_type(data, ISO);
	else if (key == K2_KEY)
		swap_project_type(data, PARA);
	return (key_press1(key, data));
}

int		key_press(int key, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (key == ESC_KEY)
		data->input_buffers.esc = 0;
	else if (key == NKPL_KEY)
	{
		data->input_buffers.increase = 1;
		increase_z(data);
	}
	else if (key == NKMN_KEY)
	{
		data->input_buffers.decrease = 1;
		decrease_z(data);
	}
	else if (key == UP_KEY)
		move_up(data);
	else if (key == DOWN_KEY)
		move_down(data);
	else if (key == RIGHT_KEY)
		move_right(data);
	else if (key == LEFT_KEY)
		move_left(data);
	return (key_press0(key, data));
}
