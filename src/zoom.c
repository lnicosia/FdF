/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:02:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 18:35:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	zoom_in(t_env *data)
{
	data->scale.x += data->delta.x;
	redraw(data);
}

void	zoom_out(t_env *data)
{
	if (data->scale.x - data->delta.x >= 0)
	{
		data->scale.x -= data->delta.x;
		redraw(data);
	}
}
