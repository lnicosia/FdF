/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:05:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 15:45:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
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

void	process_all(t_env *data)
{
	rotate_map(*data);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
}

void	swap_trace_type(t_env *data)
{
	data->input_buffers.a = 0;
	data->config.trace_type = data->config.trace_type == AA ? NORMAL : AA;
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
	put_log("\n[PROJECT TYPE SWAP]\n", 0);
	set_ranges(data);
	center(data);
	process_all(data);
}
