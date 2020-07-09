/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:17:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 14:53:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "utils.h"
#include "color_pickers.h"
#include "buttons.h"

void	draw_button_up(t_coord2 c, t_coord2 size, t_env data)
{
	int			x;
	int			y;
	t_coord2	end;
	t_coord2	colors;

	if (data.config.black_white == 1)
		colors = new_coord2(0xFFFFFF, 0x808080);
	else
		colors = new_coord2(0x606060, 0x303030);
	y = c.y - 1;
	end = new_coord2(c.x + size.x, c.y + size.y);
	while (++y < end.y)
	{
		x = c.x - 1;
		while (++x < end.x)
			if (y < end.y - 3 && x < end.x - 2)
				data.img.str[y * data.config.s_width + x] = colors.x;
			else
				data.img.str[y * data.config.s_width + x] = colors.y;
	}
}

void	draw_button_pressed(t_coord2 c, t_coord2 size, t_env data)
{
	int	xend;
	int	yend;
	int	x;
	int	y;
	int	color;

	if (data.config.black_white == 1)
		color = 0x808080;
	else
		color = 0x303030;
	y = c.y;
	xend = c.x + size.x;
	yend = c.y + size.y;
	while (y < yend)
	{
		x = c.x;
		while (x < xend)
		{
			data.img.str[y * data.config.s_width + x] = color;
			x++;
		}
		y++;
	}
}

void	put_res_buttons(t_env data)
{
	if (data.config.s_width == 2560)
		draw_button_pressed(new_coord2(25, 30), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 30), new_coord2(140, 30), data);
	if (data.config.s_width == 1920)
		draw_button_pressed(new_coord2(25, 70), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 70), new_coord2(140, 30), data);
	if (data.config.s_width == 1366)
		draw_button_pressed(new_coord2(25, 110), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 110), new_coord2(140, 30), data);
	if (data.config.s_width == 1024)
		draw_button_pressed(new_coord2(25, 150), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 150), new_coord2(140, 30), data);
	if (data.config.s_width == 800)
		draw_button_pressed(new_coord2(25, 190), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 190), new_coord2(140, 30), data);
}

void	trace_separator(t_env data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data.config.s_height)
	{
		x = 190;
		while (x <= 192)
		{
			data.img.str[y * data.config.s_width + x] = 0xA0A0A0;
			x++;
		}
		while (x <= 198)
		{
			data.img.str[y * data.config.s_width + x] = 0x808080;
			x++;
		}
		while (x <= 200)
		{
			data.img.str[y * data.config.s_width + x] = 0xA0A0A0;
			x++;
		}
		y++;
	}
}

void	trace_menu(t_env data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	if (data.config.black_white == 0)
		color = data.menu_color;
	else
		color = data.background_color;
	while (y < data.config.s_height)
	{
		x = -1;
		while (++x <= 190)
			data.img.str[y * data.config.s_width + x] = color;
		y++;
	}
	trace_separator(data);
	put_res_buttons(data);
	put_black_white_button(data);
	put_centers_button(data);
	put_color_button(data);
	put_increase_buttons(data);
	put_color_pickers(data);
	if (data.config.color == 2)
		put_increase_color_buttons(data);
}
