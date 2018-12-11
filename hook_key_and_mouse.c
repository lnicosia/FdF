/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_and_mouse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:34:47 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 17:56:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "utils.h"
#include "mlx_keycode.h"

int		key_press(int key, void *param)
{
	t_env	*data;

	data = (t_env*)param;
	if (key == ESC_KEY)
	{
		ft_putendl("ESCAPE");
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	else if (key == UP_KEY)
	{
		ft_putendl("UP_KEY");
		data->z_scale++;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
		data->img.str = mlx_get_data_addr(data->img_ptr, &(data->img.bit_per_pixels), &(data->img.size_line), &(data->img.endian));
		trace(*data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	}
	else if (key == DOWN_KEY)
	{
		ft_putendl("DOWN_KEY");
		data->z_scale--;
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
		data->img.str = mlx_get_data_addr(data->img_ptr, &(data->img.bit_per_pixels), &(data->img.size_line), &(data->img.endian));
		trace(*data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	}
	else
		ft_putendl("Coucou");
	return (0);
}

int		key_release(int key, void *param)
{
	(void)key;
	(void)param;
	return (0);
}

int		mouse_press(int button, int x, int y, void *param)
{
	(void)button;
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	(void)button;
	(void)param;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
