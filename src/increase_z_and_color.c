/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:58:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/11 12:10:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"
#include <stdio.h>

void	increase_z(t_env *data)
{
	if (data->zmax * (data->scale.z + data->delta_scale.z) <= data->zlimit)
	data->scale.z += data->delta_scale.z;
	printf("zmax * scale = %f\n", data->zmax * data->scale.z);
	process_all(data);
}

void	decrease_z(t_env *data)
{
	data->scale.z -= data->delta_scale.z;
	process_all(data);
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
