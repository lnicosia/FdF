/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_button_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:34:40 by lnicosia          #+#    #+#             */
/*   Updated: 2023/02/15 16:51:29 by lumenthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"

void	put_res_button_strings(t_env data)
{
	int	c;

	c = data.config.black_white == 1 ? 0 : 0xFFFFFF;
	if (data.config.s_width == 2560)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 49, c, "2560 x 1440");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 48, c, "2560 x 1440");
	if (data.config.s_width == 1920)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 89, c, "1920 x 1080");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 88, c, "1920 x 1080");
	if (data.config.s_width == 1366)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 130, c, "1366 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 128, c, "1366 x 768");
	if (data.config.s_width == 1024)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 169, c, "1024 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 168, c, "1024 x 768");
	if (data.config.s_width == 800)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 209, c, "800 x 600");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 208, c, "800 x 600");
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
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 269, color,
				"Black & White");
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 267, 0x00FF00, "[B]");
	}
	else
	{
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 268, color,
				"Black & White");
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 267, color, "[B]");
	}
}

void	put_centers_button_strings(t_env data)
{
	int	c;

	c = data.config.black_white == 1 ? 0 : 0xFFFFFF;
	if (data.config.centers == 0)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 309, c, "Normal");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 308, c, "Normal");
	}
	else if (data.config.centers == 1)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 60, 309, c, "Centers");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 60, 308, c, "Centers");
	}
	else if (data.config.centers == 2)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 309, c, "Triangles");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 308, c, "Triangles");
	}
}

void	put_centers_key_strings(t_env data)
{
	if (data.input_buffers.centers_button != 0)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 307, 0x00FF00, "[M]");
	else
	{
		if (data.config.black_white == 1)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 307, 0, "[M]");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 307, 0xFFFFFF,
					"[M]");
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
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 54, 23,
				color, "+");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 54, 22,
				color, "+");
	if (data.input_buffers.decrease == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 24, 23,
				color, "-");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 24, 22,
				color, "-");
}
