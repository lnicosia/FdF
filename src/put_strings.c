/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:02:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/09 13:07:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"

void	put_res_button_strings(t_env data)
{
	int	color;

	if (data.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.s_width == 2560)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 35, color, "2560 x 1440");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 32, color, "2560 x 1440");
	if (data.s_width == 1920)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 75, color, "1920 x 1080");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 72, color, "1920 x 1080");
	if (data.s_width == 1366)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 115, color, "1366 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 112, color, "1366 x 768");
	if (data.s_width == 1024)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 155, color, "1024 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 152, color, "1024 x 768");
	if (data.s_width == 800)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 195, color, "800 x 600");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 192, color, "800 x 600");
}

void	put_black_white_button_strings(t_env data)
{
	int	color;

	if (data.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.black_white == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 255, color, "Black & White");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 252, color, "Black & White");
	if (data.black_white == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 255, 0, "[B]");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 252, 0xFFFFFF, "[B]");
}

void	put_centers_button_strings(t_env data)
{
	int	color;

	if (data.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.centers == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 35, 295, color, "Show centers");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 35, 292, color, "Show centers");
	if (data.black_white == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 295, 0, "[M]");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 292, 0xFFFFFF, "[M]");
}

void	put_increase_buttons_strings(t_env data)
{
	int	color;

	if (data.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.increase_pressed == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.s_width - 56, 8, color, "+");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.s_width - 56, 8, color, "+");
	if (data.decrease_pressed == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.s_width - 26, 8, color, "-");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.s_width - 26, 8, color, "-");
}

void	put_strings(t_env data)
{
	if (data.black_white == 0)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 5, data.strings_color, "MENU");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 5, 0xFFFFFF, "MENU");
	put_res_button_strings(data);
	put_black_white_button_strings(data);
	put_centers_button_strings(data);
	put_increase_buttons_strings(data);
}
