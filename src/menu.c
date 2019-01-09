/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:17:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/09 15:39:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <mlx.h>

void	draw_button_up(t_coord2 c, t_coord2 size, t_env data)
{
	int	xend;
	int	yend;
	int	x;
	int	y;
	t_coord2 colors;

	if (data.config.black_white == 1)
	{
		colors.x = 0xFFFFFF;
		colors.y = 0x808080;
	}
	else
	{
		colors.x = 0x606060;
		colors.y = 0x303030;
	}
	y = c.y;
	xend = c.x + size.x;
	yend = c.y + size.y;
	while (y < yend)
	{
		x = c.x;
		while (x < xend)
		{
			if (y < yend - 3)
				data.img.str[y * data.config.s_width + x] = colors.x;	
			else
				data.img.str[y * data.config.s_width + x] = colors.y;
			x++;
		}
		data.img.str[y * data.config.s_width + x] = colors.y;
		data.img.str[y * data.config.s_width + x - 1] = colors.y;
		y++;
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

void	put_black_white_button(t_env data)
{
	if (data.config.black_white == 1)
		draw_button_pressed(new_coord2(25, 250), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 250), new_coord2(140, 30), data);
}

void	put_centers_button(t_env data)
{
	if (data.config.centers == 1)
		draw_button_pressed(new_coord2(25, 290), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 290), new_coord2(140, 30), data);
}

void	put_increase_buttons(t_env data)
{
	if (data.input_buffers.increase == 1)
		draw_button_pressed(new_coord2(data.config.s_width - 60, 10), new_coord2(20, 20), data);
	else
		draw_button_up(new_coord2(data.config.s_width - 60, 10), new_coord2(20, 20), data);
	if (data.input_buffers.decrease == 1)
		draw_button_pressed(new_coord2(data.config.s_width - 30, 10), new_coord2(20, 20), data);
	else
		draw_button_up(new_coord2(data.config.s_width - 30, 10), new_coord2(20, 20), data);
}

void	put_color_button(t_env data)
{
	if (data.input_buffers.color_button == 1)
		draw_button_pressed(new_coord2(25, 330), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 330), new_coord2(140, 30), data);
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
		x = 0;
		while (x <= 190)
		{
			data.img.str[y * data.config.s_width + x] = color;
			x++;
		}
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
	put_res_buttons(data);
	put_black_white_button(data);
	put_centers_button(data);
	put_color_button(data);
	put_increase_buttons(data);
}
