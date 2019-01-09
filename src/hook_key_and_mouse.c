/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/09 13:29:23 by lnicosia         ###   ########.fr       */
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
	{
		data->increase_pressed = 1;
		increase_z(data);
	}
	else if (key == NKMN_KEY)
	{
		data->decrease_pressed = 1;
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
	else if (key == A_KEY)
		swap_trace_type(data);
	else if (key == D_KEY)
	{
		data->debug = data->debug == 1 ? 0 : 1;
		redraw(data);
	}
	else if (key == K1_KEY)
		swap_project_type(data, ISO);
	else if (key == K2_KEY)
		swap_project_type(data, PARA);
	else if (key == K3_KEY)
		swap_project_type(data, FLAT);
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
	else if (key == M_KEY)
	{
		data->centers = data->centers == 1 ? 0 : 1;
		redraw(data);
	}
	else if (key == B_KEY)
	{
		data->black_white = data->black_white == 1 ? 0 : 1;
		data->centers_color = data->black_white == 1 ? 0 : 0xFFFFFF;
		redraw(data);
	}
	else
		ft_putendl("Coucou");
	return (0);
}

int		key_release(int key, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (key == NKPL_KEY)
	{
		data->increase_pressed = 0;
		increase_z(data);
	}
	else if (key == NKMN_KEY)
	{
		data->decrease_pressed = 0;
		decrease_z(data);
	}
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (button == SCROLLUP_KEY)
	{
		zoom_in(data, x, y);
	}
	else if (button == SCROLLDOWN_KEY)
	{
		zoom_out(data, x, y);
	}
	else if (button == BUT1_KEY)
	{
		printf("button\n");
		if (x >= data->s_width - 60 && x <= data->s_width - 40 && y >= 10 && y <= 30)
		{
			data->increase_pressed = 1;
			printf("+\n");
			increase_z(data);
		}
		if (x >= data->s_width - 30 && x <= data->s_width - 10 && y >= 10 && y <= 30)
		{
			data->decrease_pressed = 1;
			decrease_z(data);
		}
		else if (y >= 0 && x > 200)
		{
			data->button1_state = 1;
			data->drag_start.x = x;
			data->drag_start.y = y;
		}
		else if (x >= 25 && x <= 165)
		{
				if (y >= 30 && y <= 60)
				{
					data->s_width = 2560;
					data->s_height = 1440;
					new_window(data);
				}
				else if (y >= 70 && y <= 100)
				{
					data->s_width = 1920;
					data->s_height = 1080;
					new_window(data);
				}
				else if (y >= 110 && y <= 140)
				{
					data->s_width = 1366;
					data->s_height = 768;
					new_window(data);
				}
				else if (y >= 150 && y <= 180)
				{
					data->s_width = 1024;
					data->s_height = 768;
					new_window(data);
				}
				else if (y >= 190 && y <= 220)
				{
					data->s_width = 800;
					data->s_height = 600;
					new_window(data);
				}
				else if (y >= 250 && y <= 280)
				{
					data->black_white = data->black_white == 1 ? 0 : 1;
					data->centers_color = data->black_white == 1 ? 0 : 0xFFFFFF;
					redraw(data);
				}
				else if (y >= 290 && y <= 320)
				{
					data->centers = data->centers == 1 ? 0 : 1;
					redraw(data);
				}
		}
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
	if (button == BUT1_KEY)
	{
		data->button1_state = 0;
		if (x >= data->s_width - 60 && x <= data->s_width - 40 && y >= 10 && y <= 30)
		{
			data->increase_pressed = 0;
			redraw(data);
		}
		if (x >= data->s_width - 30 && x <= data->s_width - 10 && y >= 10 && y <= 30)
		{
			data->decrease_pressed = 0;
			redraw(data);
		}
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
		//printf("Ax [%f]	Az [%f]\n", data->angle.x, data->angle.z);
		process_all(data);
		data->drag_start.x = x;
		data->drag_start.y = y;
	}
	return (0);
}
