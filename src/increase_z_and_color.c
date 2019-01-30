/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:58:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 17:09:15 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"
#include <stdio.h>

void	increase_z(t_env *data)
{
	if (ft_abs(data->map[data->zmax].z * (data->scale.z + data->delta_scale.z))
			< data->zlimit)
	{
		data->scale.z += data->delta_scale.z;
		process_all(data);
	}
}

void	decrease_z(t_env *data)
{
	if (ft_abs(data->map[data->zmax].z * (data->scale.z - data->delta_scale.z))
			< data->zlimit)
	{
		data->scale.z -= data->delta_scale.z;
		process_all(data);
	}
}

void	increase_color_div(t_env *data)
{
	data->color_div++;
}

void	decrease_color_div(t_env *data)
{
	if (data->color_div > 1)
		data->color_div--;
}
