/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:28:48 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/02 15:42:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"

void	move_up(t_env *data)
{
	data->delta_move.y -= data->s_height / 50;
	move_map(*data);
	redraw(data);
}

void	move_down(t_env *data)
{
	data->delta_move.y += data->s_height / 50;
	move_map(*data);
	redraw(data);
}

void	move_right(t_env *data)
{
	data->delta_move.x += data->s_width / 50;
	move_map(*data);
	redraw(data);
}

void	move_left(t_env *data)
{
	data->delta_move.x -= data->s_width / 50;
	move_map(*data);
	redraw(data);
}
