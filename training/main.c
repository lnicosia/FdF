/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:24:26 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/04 17:55:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../mlx_keycode.h"
#include "libft.h"
#include "test.h"

int		key_input(int key, void *param)
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

int		main(void)
{
	t_env	data;
	int		i;

	i = 0;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Test");
	mlx_key_hook(data.win_ptr, key_input, &data);
	//draw_segment(240, 240, 260, 260, data.mlx_ptr, data.win_ptr);
	plotLine(0, 200, 500, 400, data.mlx_ptr, data.win_ptr);
	mlx_loop(data.mlx_ptr);
	return (0);
}
