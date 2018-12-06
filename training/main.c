/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:24:26 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/06 11:30:07 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../mlx_keycode.h"
#include "libft.h"
#include "test.h"

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
	else
		ft_putendl("Coucou");
	return (0);
}

int		close_window(void *param)
{
	(void)param;
	ft_putendl("CLOSE");
	exit(0);
}

int		main(void)
{
	t_env	data;
	int		i;
	t_img	img;

	i = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Test");
	mlx_hook(data.win_ptr, 3, 1L<<0 , key_press, &data);
	mlx_hook(data.win_ptr, 17, 1L<<17, close_window, &data);
	//draw_segment(240, 240, 260, 260, data.mlx_ptr, data.win_ptr);
	data.img_ptr = mlx_new_image(data.mlx_ptr, 500, 500);
	img.str = mlx_get_data_addr(data.img_ptr, &(img.bit_per_pixels), &(img.size_line), &(img.endian));
	ft_putstr("bit_per_pixels: "); ft_putnbr(img.bit_per_pixels); ft_putchar('\n');
	ft_putstr("size_line: "); ft_putnbr(img.size_line); ft_putchar('\n');
	plotLine(0, 0, 500, 500, img);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
