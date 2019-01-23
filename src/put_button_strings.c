/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_button_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:34:40 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 15:35:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "utils.h"

void	put_res_button_strings(t_env data)
{
	int	c;

	c = data.config.black_white == 1 ? 0 : 0xFFFFFF;
	if (data.config.s_width == 2560)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 34, c, "2560 x 1440");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 33, c, "2560 x 1440");
	if (data.config.s_width == 1920)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 74, c, "1920 x 1080");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 40, 73, c, "1920 x 1080");
	if (data.config.s_width == 1366)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 115, c, "1366 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 113, c, "1366 x 768");
	if (data.config.s_width == 1024)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 154, c, "1024 x 768");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 43, 153, c, "1024 x 768");
	if (data.config.s_width == 800)
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 194, c, "800 x 600");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 193, c, "800 x 600");
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
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 254, color,
				"Black & White");
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 252, 0x00FF00, "[B]");
	}
	else
	{
		mlx_string_put(data.mlx_ptr, data.win_ptr, 30, 253, color,
				"Black & White");
		mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 252, color, "[B]");
	}
}

void	put_centers_button_strings(t_env data)
{
	int	c;

	c = data.config.black_white == 1 ? 0 : 0xFFFFFF;
	if (data.config.centers == 0)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 294, c, "Normal");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 65, 293, c, "Normal");
	}
	else if (data.config.centers == 1)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 60, 294, c, "Centers");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 60, 293, c, "Centers");
	}
	else if (data.config.centers == 2)
	{
		if (data.input_buffers.centers_button != 0)
			mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 294, c, "Triangles");
		else
			mlx_string_put(data.mlx_ptr, data.win_ptr, 50, 293, c, "Triangles");
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
			mlx_string_put(data.mlx_ptr, data.win_ptr, 210, 292, 0xFFFFFF,
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
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 56, 8,
				color, "+");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 56, 7,
				color, "+");
	if (data.input_buffers.decrease == 1)
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 26, 8,
				color, "-");
	else
		mlx_string_put(data.mlx_ptr, data.win_ptr, data.config.s_width - 26, 7,
				color, "-");
}
