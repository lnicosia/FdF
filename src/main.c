/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/02 16:33:07 by lnicosia         ###   ########.fr       */
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

void	init_hook(t_env *data)
{
	mlx_hook(data->win_ptr, KEYPRESS, KEYPRESSMASK, key_press, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_window,
			data);
	mlx_hook(data->win_ptr, BUTTONPRESS, BUTTONPRESSMASK, mouse_press, data);
}

void	init_data(t_env *data)
{
	data->s_width = 1000;
	data->s_height = 1000;
	data->map_height = 0;
	data->map_width = 0;
	data->scale.x = 1;
	data->scale.y = 1;
	data->scale.z = 1;
	data->start.x = 0;
	data->start.y = 0;
	data->zmax = 0;
	data->zbuffer = 0;
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
	data->color_div = 25;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->s_width, data->s_height,
			"Fdf");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
			&(data->img.bit_per_pixels), &(data->img.size_line), &(data->img.endian));
	data->project_type = ISO;
	data->trace_type = NORMAL;
	data->pre_project[ISO] = &pre_iso_project;
	data->pre_project[PARA] = &pre_para_project;
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
	init_cos_data(&data);
	init_sin_data(&data);
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
	data.map = init_map(data.map_height, data.map_width, map);
	data.rotated_map = (t_fcoord3 *)malloc(sizeof(*data.rotated_map) * data.map_width * data.map_height);
	data.projected_map = (t_fcoord3 *)malloc(sizeof(*data.projected_map) * data.map_width * data.map_height);
	data.moved_map = (t_coord2 *)malloc(sizeof(*data.moved_map) * data.map_width * data.map_height);
	//print_map(data, data.map);
	set_ranges(&data);
	set_z_ranges(&data);
	float_map(data);
	project_map(data);
	scale_map(data);
	move_map(data);
	ft_putstr(GREEN);
	ft_putstr("[MAP CENTERED]");
	ft_putendl(RESET);
	//exit(0);
	trace(data);
	/*plot_line(new_coord2(0, data.s_height / 2), new_coord2(data.s_width, data.s_height / 2), data, 0xFFFFFF);
	plot_line(new_coord2(data.s_width / 2, 0), new_coord2(data.s_width / 2, data.s_height), data, 0xFFFFFF);*/
	printf("start[x] = %d	start[y] = %d\n", data.start.x, data.start.y);
	//zoom_in(&data, 0, 0);
	//exit(0);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
