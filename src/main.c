/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/11 11:52:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "color.h"
#include "utils.h"
#include "math.h"
#include "user_functions.h"
#include <stdio.h>

void	print_map(t_env data, t_coord3 *map)
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
			ft_putnbr(map[k].x);
			ft_putchar(' ');
			ft_putnbr(map[k].y);
			ft_putchar(' ');
			ft_putnbr(map[k].z);
			ft_putchar('\n');
			j++;
			k++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	set_background(t_env data, int color)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < data.config.s_height)
	{
		j = 0;
		while (j < data.config.s_width)
		{
			data.img.str[k] = color;
			j++;
			k++;
		}
		i++;
	}
}

void	init_hook(t_env *data)
{
	mlx_hook(data->win_ptr, KEYPRESS, KEYPRESSMASK, key_press, data);
	mlx_hook(data->win_ptr, KEYRELEASE, KEYRELEASE, key_release, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_window,
			data);
	mlx_hook(data->win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press, data);
	mlx_hook(data->win_ptr, BUTTONRELEASE, BUTTONRELEASEMASK, mouse_release, data);
	mlx_hook(data->win_ptr, MOTIONNOTIFY, BUTTON1MOTIONMASK, mouse_move, data);
}

int		init_zbuffer(t_env *data)
{
	int	i;
	int	j;
	int	k;

	if (!(data->zbuffer = (int*)malloc(sizeof(int) * data->config.s_width * data->config.s_height)))
		return (0);
	i = 0;
	k = 0;
	while (i < data->config.s_height)
	{
		j = 0;
		while (j < data->config.s_width)
		{
			data->zbuffer[k] = 2147483647;
			j++;
			k++;
		}
		i++;
	}
	return (1);
}

void	init_data(t_env *data)
{
	data->config.s_width = 1920;
	data->config.s_height = 1080;
	data->map_height = 0;
	data->map_width = 0;
	data->config.debug = 0;
	data->strings_color = 0;
	data->menu_color = 0xFFFFFF;
	data->background_color = 0x404040;
	data->edges_color = 0xFFFFFF;
	data->picked_color = 0xFFFFFF;
	data->config.black_white = 0;
	data->centers_color = 0xFFFFFF;
	data->config.centers = 0;
	data->input_buffers.increase = 0;
	data->input_buffers.decrease = 0;
	data->input_buffers.button1 = 0;
	data->input_buffers.color_button = 0;
	data->input_buffers.increase_color = 0;
	data->input_buffers.decrease_color = 0;
	data->scale.x = 1;
	data->scale.y = 1;
	data->scale.z = 1;
	data->start.x = 0;
	data->start.y = 0;
	data->zmax = 0;
	data->zlimit = 0;
	data->angle.x = 0;
	data->angle.y = 0;
	data->angle.z = 0;
	data->move.x = 0;
	data->move.y = 0;
	data->delta_move.x = 0;
	data->delta_move.y = 0;
	data->delta_scale.x = 1;
	data->delta_scale.y = 1;
	data->delta_scale.z = 0;
	data->drag_start = new_coord2(0,0);
	data->color_div = 25;
	data->config.color = 0;
	data->config.file_color = 0;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->config.s_width, data->config.s_height,
			"Fdf");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->config.s_width, data->config.s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line), &(data->img.endian));
	data->config.project_type = ISO;
	data->config.trace_type = NORMAL;
	data->pre_project[ISO] = &pre_iso_project;
	data->pre_project[PARA] = &pre_para_project;
	data->pre_project[FLAT] = &pre_flat_project;
	data->pre_project[PC] = &pre_pc_project;
}

int		main(int argc, char **argv)
{
	t_env		data;
	int			ret;
	t_list		*map;

	if (argc != 2)
	{
		ft_putstr(RED);
		ft_putstr("[WRONG NUMBER OF FILE]");
		ft_putendl(RESET);
		return (1);
	}
	map = NULL;
	init_data(&data);
	init_hook(&data);
	if ((ret = parser(&map, argv[1], &(data.map_height), &(data.map_width)))
			!= 0)
	{
		ft_putstr(RED);
		ft_putstr("[PARSE ERROR]");
		ft_putendl(RESET);
		ft_putnbr(ret);
		ft_putchar('\n');
		return (ret);
	}
	init_zbuffer(&data);
	data.file_colors = (int*)malloc(sizeof(int) * data.map_width * data.map_height);
	init_map(data.map_height, data.map_width, map, &data);
	data.rotated_map = (t_fcoord3*)malloc(sizeof(*data.rotated_map) * data.map_width * data.map_height);
	data.projected_map = (t_fcoord2*)malloc(sizeof(*data.projected_map) * data.map_width * data.map_height);
	data.moved_map = (t_coord2*)malloc(sizeof(*data.moved_map) * data.map_width * data.map_height);
	set_background(data, data.background_color);
	trace_menu(data);
	set_ranges(&data);
	set_z_ranges(&data);
	float_map(data);
	project_map(data);
	scale_map(data);
	move_map(data);
	ft_putstr(GREEN);
	ft_putstr("[MAP CENTERED]");
	ft_putendl(RESET);
	trace(data);
	fill_obj(data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	put_strings(data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
