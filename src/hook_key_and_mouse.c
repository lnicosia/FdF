/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/29 21:30:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "user_functions.h"
#include "mlx_keycode.h"
#include <stdio.h>

int		key_release(int key, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (key == ESC_KEY)
		quit(data);
	else if (key == A_KEY)
		swap_trace_type(data);
	else if (key == NKPL_KEY)
		data->input_buffers.increase = 0;
	else if (key == NKMN_KEY)
		data->input_buffers.decrease = 0;
	else if (key == C_KEY)
		data->input_buffers.color_button = 0;
	else if (key == PT_KEY)
		data->input_buffers.decrease_color = 0;
	else if (key == CM_KEY)
		data->input_buffers.increase_color = 0;
	else if (key == M_KEY)
		data->input_buffers.centers_button = 0;
	redraw(data);
	return (0);
}

void	mouse_release1(int button, t_env *data)
{
	if (button == BUT2_KEY)
	{
		if (data->input_buffers.color_button == 2)
		{
			data->input_buffers.color_button = 0;
			data->config.color--;
			if (data->config.color < 0)
				data->config.color = 2;
		}
		else if (data->input_buffers.centers_button == 2)
		{
			data->input_buffers.centers_button = 0;
			data->config.centers--;
			if (data->config.centers < 0)
				data->config.centers = 2;
		}
	}
	redraw(data);
}

void	mouse_release0(int button, t_env *data)
{
	if (button == BUT1_KEY)
	{
		if (data->input_buffers.increase_color == 1)
		{
			data->input_buffers.increase_color = 0;
			increase_color_div(data);
		}
		if (data->input_buffers.decrease_color == 1)
		{
			data->input_buffers.decrease_color = 0;
			decrease_color_div(data);
		}
		if (data->input_buffers.centers_button == 1)
			data->input_buffers.centers_button = 0;
		if (data->input_buffers.color_button == 1)
		{
			data->input_buffers.color_button = 0;
			data->config.color++;
			if (data->config.color > 2)
				data->config.color = 0;
		}
	}
	mouse_release1(button, data);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	(void)x;
	(void)y;
	if (button == BUT1_KEY)
	{
		data->input_buffers.button1 = 0;
		if (data->input_buffers.increase == 1)
		{
			data->input_buffers.increase = 0;
			increase_z(data);
		}
		if (data->input_buffers.decrease == 1)
		{
			data->input_buffers.decrease = 0;
			decrease_z(data);
		}
	}
	mouse_release0(button, data);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (data->input_buffers.button1 == 1)
	{
		data->angle.x += 0.00314159265 * (y - data->drag_start.y);
		data->angle.z -= 0.00314159265 * (x - data->drag_start.x);
		process_all(data);
		data->drag_start.x = x;
		data->drag_start.y = y;
		redraw(data);
	}
	return (0);
}
