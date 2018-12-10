/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:24:26 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 19:12:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "utils.h"

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

int		main(int argc, char **argv)
{
	t_env	data;
	int		ret;
	t_img	img;
	t_list	*map;

	map = NULL;
	data.s_height = 600;
	data.s_width = 800;
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
	/*ft_putendl("Pre filled map:");
	print_map(data);*/
	project(data);
	/*ft_putendl("Post project map:");
	print_map(data);*/
	trace(data, img);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
