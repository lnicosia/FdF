/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:59:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 18:14:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "user_functions.h"
#include "color.h"

void	new_window(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->config.s_width, data->
			config.s_height, "FdF");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->config.s_width, data->
			config.s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line),
			&(data->img.endian));
	init_hook(data);
	trace_menu(*data);
	set_ranges(data);
	center(data);
	rotate_map(*data);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
	set_screen(data);
}

void	set_screen(t_env *data)
{
	set_background(*data);
	if (data->config.project_type == PC)
	{
		data->fzmax = fmax3(data->rotated_map, data->map_height * data->
				map_width, 'z');
		data->fzmin = fmin3(data->rotated_map, data->map_height * data->
				map_width, 'z');
		data->light_range = ft_fabs(data->fzmax - data->fzmin);
		fill_obj(data);
	}
	else
	{
		if (data->config.trace_type == NORMAL)
			trace(*data);
		else
			trace_aa(*data);
		print_centers(*data);
	}
	if (data->config.debug == 1)
		draw_axes(data);
	trace_menu(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	put_strings(*data);
}

void	redraw(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	set_screen(data);
}
