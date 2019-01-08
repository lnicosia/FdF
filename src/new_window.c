/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:59:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/08 18:08:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "user_functions.h"
#include "color.h"

void	new_window(t_env *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->s_width, data->s_height, "Fdf");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line),
			&(data->img.endian));
	set_background(*data, data->background_color);
	trace_menu(*data);
	set_ranges(data);
	set_z_ranges(data);
	float_map(*data);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
	ft_putstr(GREEN);
	ft_putstr("[MAP CENTERED]");
	ft_putendl(RESET);
	trace(*data);
	fill_obj(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	put_strings(*data);
	//mlx_loop(data->mlx_ptr);
}
