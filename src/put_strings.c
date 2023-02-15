/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 17:02:14 by lnicosia          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:49 by lumenthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "put_button_strings.h"

void	put_debug_strings(t_env data)
{
	if (data.config.debug == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 100,
				data.config.s_height - 60, 0x00FF00, "[D]Debug");
	else
	{
		if (data.config.black_white == 1)
			mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width -
					100, data.config.s_height - 60, 0, "[D]Debug");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width -
					100, data.config.s_height - 60, 0xFFFFFF, "[D]Debug");
	}
}

void	put_color_strings(t_env data)
{
	int	color;
	int	y;

	y = 333;
	if (data.input_buffers.color_button == 0)
		y += 2;
	if (data.config.black_white == 1)
		color = 0;
	else
		color = 0xFFFFFF;
	if (data.config.color == 0)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, y + 15, color,
				"Color: pick");
	else if (data.config.color == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, y + 15, color,
				"Color: file");
	else if (data.config.color == 2)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, y + 15, color,
				"Color: earth");
}

void	put_color_key_strings(t_env data)
{
	if (data.input_buffers.color_button == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 347, 0x00FF00, "[C]");
	else
	{
		if (data.config.black_white == 1)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 347, 0, "[C]");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 347, 0xFFFFFF,
					"[C]");
	}
}

void	put_increase_color_buttons_strings(t_env data)
{
	int	color;

	if (data.config.black_white == 1)
		return ;
	color = 0xFFFFFF;
	if (data.input_buffers.increase_color == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 54, 54,
				color, "<");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 54, 53,
				color, "<");
	if (data.input_buffers.decrease_color == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 23, 54,
				color, ">");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 23, 53,
				color, ">");
}

void	put_strings(t_env data)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, 80, 18, data.strings_color, "MENU");
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
