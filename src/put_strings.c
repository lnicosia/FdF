/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:02:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/14 12:37:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"

void	put_res_button_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.config.s_width == 2560)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 34, color, "2560 x 1440");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 33, color, "2560 x 1440");
	if (data.config.s_width == 1920)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 74, color, "1920 x 1080");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 73, color, "1920 x 1080");
	if (data.config.s_width == 1366)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 115, color, "1366 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 113, color, "1366 x 768");
	if (data.config.s_width == 1024)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 154, color, "1024 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 153, color, "1024 x 768");
	if (data.config.s_width == 800)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 194, color, "800 x 600");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 193, color, "800 x 600");
}

void	put_black_white_button_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.config.black_white == 1)
	{
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 254, color, "Black & White");
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 252, 0x00FF00, "[B]");
	}
	else
	{
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 253, color, "Black & White");
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 252, 0xFFFFFF, "[B]");
	}
}

void	put_centers_button_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.config.centers == 0)
	{
		if (data.input_buffers.centers_button != 0)
		{
			mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 294, color, "Normal");
		}
		else
		{
			mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 293, color, "Normal");
		}
	}
	else if (data.config.centers == 1)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 60, 294, color, "Centers");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 60, 293, color, "Centers");
	}
	else if (data.config.centers == 2)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 294, color, "Triangles");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 293, color, "Triangles");
	}
}

void	put_centers_key_strings(t_env data)
{
	if (data.input_buffers.centers_button != 0)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 292, 0x00FF00, "[M]");
	else
	{
		if (data.config.black_white == 1)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 292, 0, "[M]");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 292, 0xFFFFFF, "[M]");
	}
}

void	put_increase_buttons_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.input_buffers.increase == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 56, 8, color, "+");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 56, 7, color, "+");
	if (data.input_buffers.decrease == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 26, 8, color, "-");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 26, 7, color, "-");
}

void	put_debug_strings(t_env data)
{
	if (data.config.debug == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 100, data.config.s_height - 30, 0x00FF00, "[D]Debug");
	else
	{
		if (data.config.black_white == 1)
			mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 100, data.config.s_height - 30, 0, "[D]Debug");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 100, data.config.s_height - 30, 0xFFFFFF, "[D]Debug");
	}
}

void	put_color_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.config.color == 0)
	{
		if (data.input_buffers.color_button == 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 333, color, "Color: pick");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 335, color, "Color: pick");
	}
	else if (data.config.color == 1)
	{
		if (data.input_buffers.color_button == 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 333, color, "Color: file");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 335, color, "Color: file");
	}
	else if (data.config.color == 2)
	{
		if (data.input_buffers.color_button == 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 333, color, "Color: earth");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 335, color, "Color: earth");
	}

}

void	put_color_key_strings(t_env data)
{
	if (data.input_buffers.color_button == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 332, 0x00FF00, "[C]");
	else
	{
		if (data.config.black_white == 1)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 332, 0, "[C]");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 332, 0xFFFFFF, "[C]");
	}
}

void	put_increase_color_buttons_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		return ;
	color = 0xFFFFFF;
	if (data.input_buffers.increase_color == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 56, 38, color, "<");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 56, 37, color, "<");
	if (data.input_buffers.decrease_color == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 25, 38, color, ">");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 25, 37, color, ">");
}

void	put_strings(t_env data)
{
	if (data.config.black_white == 0)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 5, data.strings_color, "MENU");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 5, 0xFFFFFF, "MENU");
	put_res_button_strings(data);
	put_black_white_button_strings(data);
	put_centers_button_strings(data);
	put_centers_key_strings(data);
	put_increase_buttons_strings(data);
	put_debug_strings(data);
	put_color_strings(data);
	put_color_key_strings(data);
	if (data.config.color == 2)
		put_increase_color_buttons_strings(data);
}
