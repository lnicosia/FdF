/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:24:26 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/07 15:57:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "utils.h"

int		main(int argc, char **argv)
{
	t_env	data;
	int		i;
	int		line_count;
	t_img	img;
	t_list	*map;
	t_list	*tmp;

	i = 0;
	map = NULL;
	(void)argc;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Test");
	mlx_hook(data.win_ptr, 3, 1L << 0, key_press, &data);
	mlx_hook(data.win_ptr, 17, 1L << 17, close_window, &data);
	data.img_ptr = mlx_new_image(data.mlx_ptr, 500, 500);
	img.str = mlx_get_data_addr(data.img_ptr, &(img.bit_per_pixels), &(img.size_line), &(img.endian));
	line_count = parser(&map, argv[1]);
	ft_putstr("map size: "); ft_putnbr(line_count);
	ft_putstr(" x ");ft_putnbr(ft_strlen((char *)(map->content))); ft_putchar('\n');
	ft_putendl("TXT MAP:");
	tmp = map;
	while (tmp)
	{
		//ft_putstr("len: "); ft_putnbr(map->content_size); ft_putstr(" ("); ft_putnbr(ft_strlen((char *)(map->content))); ft_putstr(") ");
		ft_putendl((char *)tmp->content);
		tmp = tmp->next;
	}
	ft_putstr("bit_per_pixels: "); ft_putnbr(img.bit_per_pixels); ft_putchar('\n');
	ft_putstr("size_line: "); ft_putnbr(img.size_line); ft_putchar('\n');
	t_coord2 c1;
	t_coord2 c2;
	c1.x = 300;
	c1.y = 500;
	c2.x = 0;
	c2.y = 0;
	plot_line(c1, c2, img);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
