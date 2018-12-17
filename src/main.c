/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:22 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 15:32:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "color.h"
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

void	init_data(t_env *data)
{
	data->s_width = 1920;
	data->s_height = 1080;
	data->map_height = 0;
	data->map_width = 0;
	data->scale.x = 1;
	data->scale.y = 1;
	data->scale.z = 1;
	data->start.x = 0;
	data->start.y = 0;
	data->delta.x = data->s_width / 25;
	data->delta.y = data->s_height / 25;
	data->delta.z = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->s_width, data->s_height, "Test");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr, &(data->img.bit_per_pixels), &(data->img.size_line), &(data->img.endian));
	data->project_type = ISO;
	data->trace_type = NORMAL;
	data->project[ISO] = &iso_project;
}

int		main(int argc, char **argv)
{
	t_env		data;
	int			ret;
	t_list		*map;

	(void)argc;
	map = NULL;
	init_data(&data);
	mlx_hook(data.win_ptr, KEYPRESS, KEYPRESSMASK, key_press, &data);
	mlx_hook(data.win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_window, &data);
	mlx_hook(data.win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press, &data);
	//mlx_hook(data.win_ptr, MOTIONNOTIFY, BUTTONMOTIONMASK, mouse_press, &data);
	if ((ret = parser(&map, argv[1], &(data.map_height), &(data.map_width))) != 0)
	{
		ft_putendl("parse error "); ft_putnbr(ret); ft_putchar('\n');
		return (ret);
	}
	ft_putstr(GREEN); ft_putstr("[PARSE OK]"); ft_putendl(RESET);
	ft_putnbr(data.s_width); ft_putstr(" X "); ft_putnbr(data.s_height); ft_putchar('\n');
	ft_putstr("map size: "); ft_putnbr(data.map_height);
	ft_putstr(" x "); ft_putnbr(data.map_width); ft_putchar('\n');
	ft_putstr("bit_per_pixels: "); ft_putnbr(data.img.bit_per_pixels); ft_putchar('\n');
	ft_putstr("size_line: "); ft_putnbr(data.img.size_line); ft_putchar('\n');
	data.map = init_map(data.map_height, data.map_width, map);
	ft_putstr(GREEN); ft_putstr("[MAP INITIALIZED]"); ft_putendl(RESET);
	//print_map(data);
	set_ranges(&data);
	ft_putstr(GREEN); ft_putstr("[MAP SCALED AND CENTERED]"); ft_putendl(RESET);
	trace(data);
	ft_putstr(GREEN); ft_putstr("[MAP TRACED]"); ft_putendl(RESET);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}