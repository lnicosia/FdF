/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:28:48 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/21 12:27:22 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"

void	move_up(t_env *data)
{
	data->start.y -= data->s_height / 50;
	center_map(*data);
	redraw(data);
}

void	move_down(t_env *data)
{
	data->start.y += data->s_height / 50;
	center_map(*data);
	redraw(data);
}

void	move_right(t_env *data)
{
	data->start.x += data->s_width / 50;
	center_map(*data);
	redraw(data);
}

void	move_left(t_env *data)
{
	data->start.x -= data->s_width / 50;
	center_map(*data);
	redraw(data);
}
