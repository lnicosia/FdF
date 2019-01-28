/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/28 11:03:00 by lnicosia         ###   ########.fr       */
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

void	first_process(t_env *data)
{
	set_background(*data);
	trace_menu(*data);
	set_ranges(data);
	set_z_ranges(data);
	center(data);
	float_map(*data);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
	put_log("[MAP CENTERED]", 0);
	trace(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	put_strings(*data);
	mlx_loop(data->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_env		data;
	int			ret;
	t_list		*map;

	if (argc != 2)
	{
		put_log("[WRONG NUMBER OF FILE]", 1);
		return (1);
	}
	map = NULL;
	init_data(&data);
	if ((ret = parser(&map, argv[1], &(data.map_height), &(data.map_width)))
			!= 0)
	{
		put_log("[PARSE ERROR]", 1);
		ft_putnbr(ret);
		ft_putchar('\n');
		return (ret);
	}
	init_arrays(&data);
	init_map(data.map_height, data.map_width, map, &data);
	init_zbuffer(&data);
	first_process(&data);
	return (0);
}
