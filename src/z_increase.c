/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:58:37 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/14 16:06:59 by lnicosia         ###   ########.fr       */
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
