/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_data->c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:17:45 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/19 18:02:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_cos_data(t_env *data)
{
	data->cos_data[0] = 1;
	data->cos_data[1] = 0.987688;
	data->cos_data[2] = 0.951057;
	data->cos_data[3] = 0.891007;
	data->cos_data[4] = 0.809017;
	data->cos_data[5] = 0.707107;
	data->cos_data[6] = 0.587785;
	data->cos_data[7] = 0.453991;
	data->cos_data[8] = 0.309017;
	data->cos_data[9] = 0.156435;
	data->cos_data[10] = 0.000000;
	data->cos_data[11] = -0.156434;
	data->cos_data[12] = -0.309017;
	data->cos_data[13] = -0.453990;
	data->cos_data[14] = -0.587785;
	data->cos_data[15] = -0.707106;
	data->cos_data[16] = -0.809017;
	data->cos_data[17] = -0.891006;
	data->cos_data[18] = -0.951056;
	data->cos_data[19] = -0.987688;
	data->cos_data[20] = -1;
}

void	init_sin_data(t_env *data)
{
	data->sin_data[0] = 0;
	data->sin_data[1] = 0.156434;
	data->sin_data[2] = 0.309017;
	data->sin_data[3] = 0.453990;
	data->sin_data[4] = 0.587785;
	data->sin_data[5] = 0.707107;
	data->sin_data[6] = 0.809017;
	data->sin_data[7] = 0.891006;
	data->sin_data[8] = 0.951056;
	data->sin_data[9] = 0.987688;
	data->sin_data[10] = 1.000000;
	data->sin_data[11] = 0.987688;
	data->sin_data[12] = 0.951057;
	data->sin_data[13] = 0.891007;
	data->sin_data[14] = 0.809017;
	data->sin_data[15] = 0.707107;
	data->sin_data[16] = 0.587786;
	data->sin_data[17] = 0.453991;
	data->sin_data[18] = 0.309018;
	data->sin_data[19] = 0.156435;
	data->sin_data[20] = 0;
}
