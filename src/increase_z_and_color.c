/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:58:37 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/18 11:49:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"

void	increase_z(t_env *data)
{
	data->scale.z += data->delta.z;
	redraw(data);
}

void	decrease_z(t_env *data)
{
	data->scale.z -= data->delta.z;
	redraw(data);
}

void	increase_color_div(t_env *data)
{
	data->color_div++;
	redraw(data);
}

void	decrease_color_div(t_env *data)
{
	if (data->color_div > 1)
	{
		data->color_div--;
		redraw(data);
	}
}