/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:24:26 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 13:19:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

void	print_map(t_env data)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (i < data.map_height)
	{
		j = 0;
		while (j < data.map_width)
		{
			ft_putnbr(data.map[k].x); ft_putchar(' ');
			ft_putnbr(data.map[k].y); ft_putchar(' ');
			ft_putnbr(data.map[k].z); ft_putchar('\n');
			j++;
			k++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_ranges(t_env data)
{
	ft_putstr("min x = "); ft_putnbr(min3(data.map, data.map_height * data.map_width, 'x')); 
	ft_putstr(" max x = "); ft_putnbr(max3(data.map, data.map_height * data.map_width, 'x'));
	ft_putchar('\n');
	ft_putstr("min y = "); ft_putnbr(min3(data.map, data.map_height * data.map_width, 'y')); 
	ft_putstr(" max y = "); ft_putnbr(max3(data.map, data.map_height * data.map_width, 'y'));
	ft_putchar('\n');
	ft_putstr("min z = "); ft_putnbr(min3(data.map, data.map_height * data.map_width, 'z')); 
	ft_putstr(" max z = "); ft_putnbr(max3(data.map, data.map_height * data.map_width, 'z'));
	ft_putchar('\n');
}

int		main(int argc, char **argv)
{
	t_env		data;
	int			ret;
	t_img		img;
	t_list		*map;
	t_coord3	max;
	t_coord3	min;
	t_coord2	start;

	map = NULL;
	data.s_height = 600;
	data.s_width = 800;
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
	data.map = init_map(data.map_height, data.map_width, map);
	/*ft_putendl("Pre process MAP:");
	print_map(data);*/
	ft_putstr("bit_per_pixels: "); ft_putnbr(img.bit_per_pixels); ft_putchar('\n');
	ft_putstr("size_line: "); ft_putnbr(img.size_line); ft_putchar('\n');
	fill_map(data);

	max.z = max3(data.map, data.map_height * data.map_width, 'z'); 
	min.z = min3(data.map, data.map_height * data.map_width, 'z');	
	//data.z_scale = (float)(max.z - min.z);
	//ft_putendl("Pre filled map:");
	//print_map(data);
	//print_ranges(data);
	project(data);
	//ft_putendl("Post project map:");
	//print_ranges(data);

	max.x = max3(data.map, data.map_height * data.map_width, 'x'); 
	max.y = max3(data.map, data.map_height * data.map_width, 'y'); 
	min.x = min3(data.map, data.map_height * data.map_width, 'x'); 
	min.y = min3(data.map, data.map_height * data.map_width, 'y');

	data.x_scale = (float)data.s_width / (float)(max.x - min.x);
	data.y_scale = (float)data.s_height / (float)(max.y - min.y);
	printf("x_scale = %f\ny_scale = %f\nz_scale = %f\n", data.x_scale, data.y_scale, data.z_scale);
	start.x = ft_abs(min.x * data.x_scale);
	start.y = ft_abs(min.y * data.y_scale);
	//print_map(data);
	scale(data);
	trace(data, img, start);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
