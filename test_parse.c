/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:50:48 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 15:00:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_env		data;
	int			ret;
	t_img		img;
	t_list		*map;

	map = NULL;
	data.s_width = 1280;
	data.s_height = 720;
	data.map_height = 0;
	data.map_width = 0;
	data.x_scale = 1;
	data.y_scale = 1;
	data.z_scale = 1;
	(void)argc;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.s_width, data.s_height, "Test");
	mlx_hook(data.win_ptr, 3, 1L << 0, key_press, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_window, &data);
	data.img_ptr = mlx_new_image(data.mlx_ptr, data.s_width, data.s_height);
	img.str = mlx_get_data_addr(data.img_ptr, &(img.bit_per_pixels), &(img.size_line), &(img.endian));
	if ((ret = parser(&map, argv[1], &(data.map_height), &(data.map_width))) != 0)
	{
		ft_putendl("parse error "); ft_putnbr(ret); ft_putchar('\n');
		return (ret);
	}
	ft_putnbr(data.s_width); ft_putstr(" X "); ft_putnbr(data.s_height); ft_putchar('\n');
	ft_putstr("map size: "); ft_putnbr(data.map_height);
	ft_putstr(" x "); ft_putnbr(data.map_width); ft_putchar('\n');
	//data.map = init_map(data.map_height, data.map_width, map);
	//mlx_loop(data.mlx_ptr);
	return (0);
}
