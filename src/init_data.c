/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:17:09 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/28 18:17:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "utils.h"

void	init_hook(t_env *data)
{
	mlx_hook(data->win_ptr, KEYPRESS, KEYPRESSMASK, key_press, data);
	mlx_hook(data->win_ptr, KEYRELEASE, KEYRELEASE, key_release, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_window,
			data);
	mlx_hook(data->win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press, data);
	mlx_hook(data->win_ptr, BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release,
			data);
	mlx_hook(data->win_ptr, MOTIONNOTIFY, BUTTON1MOTIONMASK, mouse_move, data);
}

void	init_config(t_env *data)
{
	data->config.s_width = 1920;
	data->config.s_height = 1080;
	data->config.centers = 0;
	data->config.trace = 0;
	data->config.poly = 0;
	data->config.underside = 0;
	data->config.fill = 1;
	data->config.light = 1;
	data->config.color = 0;
	data->config.file_color = 0;
	data->config.black_white = 0;
	data->config.debug = 0;
	data->config.project_type = ISO;
	data->config.trace_type = NORMAL;
}

void	init_buffers(t_env *data)
{
	data->input_buffers.increase = 0;
	data->input_buffers.decrease = 0;
	data->input_buffers.button1 = 0;
	data->input_buffers.color_button = 0;
	data->input_buffers.increase_color = 0;
	data->input_buffers.decrease_color = 0;
	data->input_buffers.centers_button = 0;
}

void	init_values(t_env *data)
{
	data->map_height = 0;
	data->map_width = 0;
	data->strings_color = 0;
	data->menu_color = 0xFFFFFF;
	data->background_color = 0x404040;
	data->edges_color = 0;
	data->picked_color = 0xFFFFFF;
	data->centers_color = 0xFFFFFF;
	data->current_color = 0xFFFFFF;
	data->norm = -1;
	data->area = 0;
	data->zmax = 0;
	data->zmin = 0;
	data->scale.x = 1;
	data->scale.y = 1;
	data->scale.z = 1;
	data->start.x = 0;
	data->start.y = 0;
	data->zrange = 0;
	data->zlimit = 0;
	data->angle.x = 0;
	data->angle.y = 0;
	data->angle.z = 0;
	data->move.x = 0;
	data->move.y = 0;
}

void	init_data(t_env *data)
{
	data->delta_move.x = 0;
	data->delta_move.y = 0;
	data->delta_scale.x = 1;
	data->delta_scale.y = 1;
	data->delta_scale.z = 0;
	data->drag_start = new_coord2(0, 0);
	data->color_div = 25;
	init_values(data);
	init_config(data);
	init_buffers(data);
	data->pre_project[ISO] = &pre_iso_project;
	data->pre_project[PARA] = &pre_para_project;
	data->pre_project[FLAT] = &pre_flat_project;
	data->pre_project[PC] = &pre_pc_project;
}
