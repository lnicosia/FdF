/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_buttons.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:50:41 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 14:54:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "buttons.h"

void	put_black_white_button(t_env data)
{
	if (data.config.black_white == 1)
		draw_button_pressed(new_coord2(25, 250), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 250), new_coord2(140, 30), data);
}

void	put_centers_button(t_env data)
{
	if (data.input_buffers.centers_button == 1)
		draw_button_pressed(new_coord2(25, 290), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 290), new_coord2(140, 30), data);
}

void	put_increase_buttons(t_env data)
{
	if (data.input_buffers.increase == 1)
		draw_button_pressed(new_coord2(data.config.s_width - 60, 10),
				new_coord2(20, 20), data);
	else
		draw_button_up(new_coord2(data.config.s_width - 60, 10),
				new_coord2(20, 20), data);
	if (data.input_buffers.decrease == 1)
		draw_button_pressed(new_coord2(data.config.s_width - 30, 10),
				new_coord2(20, 20), data);
	else
		draw_button_up(new_coord2(data.config.s_width - 30, 10), new_coord2(20,
					20), data);
}

void	put_color_button(t_env data)
{
	if (data.input_buffers.color_button != 0)
		draw_button_pressed(new_coord2(25, 330), new_coord2(140, 30), data);
	else
		draw_button_up(new_coord2(25, 330), new_coord2(140, 30), data);
}

void	put_increase_color_buttons(t_env data)
{
	if (data.config.black_white == 0)
	{
		if (data.input_buffers.increase_color == 1)
			draw_button_pressed(new_coord2(data.config.s_width - 60, 40),
					new_coord2(20, 20), data);
		else
			draw_button_up(new_coord2(data.config.s_width - 60, 40),
					new_coord2(20, 20), data);
		if (data.input_buffers.decrease_color == 1)
			draw_button_pressed(new_coord2(data.config.s_width - 30, 40),
					new_coord2(20, 20), data);
		else
			draw_button_up(new_coord2(data.config.s_width - 30, 40),
					new_coord2(20, 20), data);
	}
}
