/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:02:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/08 17:53:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"

void	put_res_button_strings(t_env data)
{
	if (data.s_width == 1920)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 35, 0xFFFFFF, "1920 x 1080");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 32, 0xFFFFFF, "1920 x 1080");
	if (data.s_width == 1366)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 75, 0xFFFFFF, "1366 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 72, 0xFFFFFF, "1366 x 768");
	if (data.s_width == 1024)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 115, 0xFFFFFF, "1024 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 112, 0xFFFFFF, "1024 x 768");
	if (data.s_width == 800)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 155, 0xFFFFFF, "800 x 600");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 152, 0xFFFFFF, "800 x 600");
}

void	put_strings(t_env data)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 5, data.strings_color, "MENU");
	put_res_button_strings(data);
}
