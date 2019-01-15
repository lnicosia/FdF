/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:05:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/15 11:01:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "color.h"
#include "user_functions.h"

void	quit(t_env *data)
{
	ft_putstr(RED);
	ft_putstr("[ESCAPE]");
	ft_putendl(RESET);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void	redraw(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->config.s_width, data->config.s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line),
			&(data->img.endian));
	if (data->config.black_white == 0)
		set_background(*data, data->background_color);
	else
		set_background(*data, 0xFFFFFF);
	if (data->config.project_type == PC)
	{
		data->fzmax = fmax3(data->rotated_map, data->map_height * data->map_width, 'z');
		data->fzmin = fmin3(data->rotated_map, data->map_height * data->map_width, 'z');
		fill_obj(*data);
	}
	else
		if (data->config.trace_type == NORMAL)
		{
			trace(*data);
			print_centers(*data);
		}
		else
			trace_aa(*data);
	if (data->config.debug == 1)
		draw_axes(data);
	trace_menu(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	put_strings(*data);
}


void	process_all(t_env *data)
{
	rotate_map(*data);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
	redraw(data);
}

void	swap_trace_type(t_env *data)
{
	data->config.trace_type = data->config.trace_type == AA ? NORMAL : AA;
	redraw(data);
}

void	swap_project_type(t_env *data, int type)
{
	data->config.project_type = type;
	if (type == FLAT)
	{
		data->angle.x = 0;
		data->angle.y = 0;
		data->angle.z = 0;
	}
	set_ranges(data);
	process_all(data);
}
