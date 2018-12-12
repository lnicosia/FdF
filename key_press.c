/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:58:37 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/12 13:38:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"
#include <stdio.h>

void	escape(t_env *data)
{
	ft_putendl("ESCAPE");
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

void	key_up(t_env *data)
{
	ft_putendl("UP_KEY");
	data->scale.z += 0.1;
	printf("z_scale = %f\n", data->scale.z);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line),
			&(data->img.endian));
	trace(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}

void	key_down(t_env *data)
{
	ft_putendl("DOWN_KEY");
	data->scale.z -= 0.1;
	printf("z_scale = %f\n", data->scale.z);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line),
			&(data->img.endian));
	trace(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
