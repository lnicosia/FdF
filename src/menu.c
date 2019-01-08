/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:17:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/08 17:44:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <mlx.h>

void	draw_button_up(t_coord2 c, t_env data)
{
	int	xend;
	int	yend;
	int	x;
	int	y;

	y = c.y;
	xend = c.x + 140;
	yend = c.y + 30;
	while (y < yend)
	{
		x = c.x;
		while (x < xend)
		{
			if (y < yend - 5)
				data.img.str[y * data.s_width + x] = 0x606060;	
			else
				data.img.str[y * data.s_width + x] = 0x404040;	
			x++;
		}
		y++;
	}

}

void	draw_button_pressed(t_coord2 c, t_env data)
{
	int	xend;
	int	yend;
	int	x;
	int	y;

	y = c.y;
	xend = c.x + 140;
	yend = c.y + 30;
	while (y < yend)
	{
		x = c.x;
		while (x < xend)
		{
			if (y >= c.y + 5)
				data.img.str[y * data.s_width + x] = 0x606060;	
			else
				data.img.str[y * data.s_width + x] = 0x404040;	
			x++;
		}
		y++;
	}

}

void	put_res_buttons(t_env data)
{
	if (data.s_width == 1920)
		draw_button_pressed(new_coord2(25, 30), data);
	else
		draw_button_up(new_coord2(25, 30), data);
	if (data.s_width == 1366)
		draw_button_pressed(new_coord2(25, 70), data);
	else
		draw_button_up(new_coord2(25, 70), data);
	if (data.s_width == 1024)
		draw_button_pressed(new_coord2(25, 110), data);
	else
		draw_button_up(new_coord2(25, 110), data);
	if (data.s_width == 800)
		draw_button_pressed(new_coord2(25, 150), data);
	else
		draw_button_up(new_coord2(25, 150), data);
}

void	trace_menu(t_env data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data.s_height)
	{
		x = 0;
		while (x <= 200)
		{
			data.img.str[y * data.s_width + x] = data.menu_color;
			x++;
		}
		y++;
	}
	put_res_buttons(data);
}
