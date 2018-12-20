/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:22 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/20 12:46:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "mlx_keycode.h"
#include "libft.h"
#include "color.h"
#include "utils.h"
#include "math.h"
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
			ft_putnbr(data.map[k].x);
			ft_putchar(' ');
			ft_putnbr(data.map[k].y);
			ft_putchar(' ');
			ft_putnbr(data.map[k].z);
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
	data->s_width = 1920;
	data->s_height = 1080;
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
	data->delta.x = data->s_width / 25;
	data->delta.y = data->s_height / 25;
	data->delta.z = 0;
	data->color_div = 25;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->s_width, data->s_height,
			"Test");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->s_width, data->s_height);
	data->img.str = (unsigned int*)mlx_get_data_addr(data->img_ptr,
	&(data->img.bit_per_pixels), &(data->img.size_line), &(data->img.endian));
	data->project_type = ISO;
	data->trace_type = NORMAL;
	data->project[ISO] = &iso_project;
	data->project[PARA] = &para_project;
	data->fproject[ISO] = &fiso_project;
	data->fproject[PARA] = &fpara_project;
	data->plot_line_low[0] = &plot_line_low;
	data->plot_line_low[1] = &plot_line_low_aa;
	data->plot_line_high[0] = &plot_line_high;
	data->plot_line_high[1] = &plot_line_high_aa;
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
	set_ranges(&data);
	set_z_ranges(&data);
	trace(data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_loop(data.mlx_ptr);
	return (0);
}
