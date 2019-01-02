/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:05:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/02 15:51:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include "color.h"

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
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line),
			&(data->img.endian));
	if (data->trace_type == NORMAL)
		trace(*data);
	else
		trace_aa(*data);
	plot_line(new_coord2(0, data->s_height / 2), new_coord2(data->s_width, data->s_height / 2), *data, 0xFFFFFF);
	plot_line(new_coord2(data->s_width / 2, 0), new_coord2(data->s_width / 2, data->s_height), *data, 0xFFFFFF);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
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
	data->trace_type = data->trace_type == AA ? NORMAL : AA;
	redraw(data);
}

void	swap_project_type(t_env *data)
{
	data->project_type = data->project_type == PARA ? ISO : PARA;
	set_ranges(data);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
	redraw(data);
}
