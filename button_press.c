/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 10:44:26 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/14 15:44:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	scroll_up(t_env *data)
{
	data->scale.x += data->delta.x;
	recenter(data);
	redraw(data);
}

void	scroll_down(t_env *data)
{
	if (data->scale.x - data->delta.x >= 0)
	{
		data->scale.x -= data->delta.x;
		recenter(data);
	}
	redraw(data);
}
