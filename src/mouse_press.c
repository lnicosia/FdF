/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:42:23 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 18:56:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "mlx_keycode.h"
#include "user_functions.h"

void	mouse_press_button1_2(int x, int y, t_env *data)
{
	if (x >= 25 && x <= 165)
	{
		if (y >= 250 && y <= 280)
		{
			data->config.black_white = data->config.black_white == 1 ? 0 :
				1;
			data->centers_color = data->config.black_white == 1 ? 0 :
				0xFFFFFF;
			data->background_color = data->config.black_white == 1 ?
				0xFFFFFF : 0x404040;
		}
		else if (y >= 290 && y <= 320)
		{
			data->config.centers++;
			if (data->config.centers > 2)
				data->config.centers = 0;
			data->input_buffers.centers_button = 1;
		}
		else if (y >= 330 && y <= 360)
			data->input_buffers.color_button = 1;
	}
}

void	mouse_press_button1_1(int x, int y, t_env *data)
{
	if (x >= 25 && x <= 165)
	{
		if (y >= 110 && y <= 140)
		{
			data->config.s_width = 1366;
			data->config.s_height = 768;
			new_window(data);
		}
		else if (y >= 150 && y <= 180)
		{
			data->config.s_width = 1024;
			data->config.s_height = 768;
			new_window(data);
		}
		else if (y >= 190 && y <= 220)
		{
			data->config.s_width = 800;
			data->config.s_height = 600;
			new_window(data);
		}
	}
	mouse_press_button1_2(x, y, data);
}

void	mouse_press_button1_0(int x, int y, t_env *data)
{
	if (x >= 15 && x <= 175 && y >= 442 && y <= 477)
		data->picked_color = ((data->picked_color >> 16 & 0xFF) << 16) |
			((data->img.str[x + y * data->config.s_width] >> 8 & 0xFF) << 8) |
			(data->picked_color & 0xFF);
	else if (x >= 15 && x <= 175 && y >= 482 && y <= 519)
		data->picked_color = ((data->picked_color >> 16 & 0xFF) << 16) |
			((data->picked_color >> 8 & 0xFF) << 8) | (data->img.str[x +
				y * data->config.s_width] & 0xFF);
	else if (x >= 25 && x <= 165)
	{
		if (y >= 30 && y <= 60)
		{
			data->config.s_width = 2560;
			data->config.s_height = 1440;
			new_window(data);
		}
		else if (y >= 70 && y <= 100)
		{
			data->config.s_width = 1920;
			data->config.s_height = 1080;
			new_window(data);
		}
	}
	mouse_press_button1_1(x, y, data);
}

void	mouse_press_button1(int x, int y, t_env *data)
{
	if (x >= data->config.s_width - 60 && x <= data->config.s_width - 40
			&& y >= 10 && y <= 30)
		data->input_buffers.increase = 1;
	else if (x >= data->config.s_width - 30 && x <= data->config.s_width -
			10 && y >= 10 && y <= 30)
		data->input_buffers.decrease = 1;
	else if (x >= data->config.s_width - 60 && x <= data->config.s_width -
			40 && y >= 40 && y <= 60 && data->config.black_white == 0)
		data->input_buffers.increase_color = 1;
	else if (x >= data->config.s_width - 30 && x <= data->config.s_width -
			10 && y >= 40 && y <= 60 && data->config.black_white == 0)
		data->input_buffers.decrease_color = 1;
	else if (y >= 0 && x > 200)
	{
		data->input_buffers.button1 = 1;
		data->drag_start.x = x;
		data->drag_start.y = y;
	}
	else if (x >= 15 && x <= 175 && y >= 400 && y <= 435)
		data->picked_color = (data->img.str[x + y * data->config.s_width] >>
				16 & 0xFF) << 16 | ((data->picked_color >> 8 & 0xFF) << 8) |
			(data->picked_color & 0xFF);
	mouse_press_button1_0(x, y, data);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (button == SCROLLUP_KEY)
		zoom_in(data, x, y);
	else if (button == SCROLLDOWN_KEY)
		zoom_out(data, x, y);
	else if (button == BUT1_KEY)
		mouse_press_button1(x, y, data);
	else if (button == BUT2_KEY)
	{
		if (x >= 25 && x <= 165 && y >= 330 && y <= 360)
			data->input_buffers.color_button = 2;
		else if (x >= 25 && x <= 165 && y >= 290 && y <= 320)
			data->input_buffers.centers_button = 2;
	}
	redraw(data);
	return (0);
}
