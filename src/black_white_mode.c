/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_white_mode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:04:53 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 16:05:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	black_white_mode(t_env *data)
{
	data->config.black_white = data->config.black_white == 1 ? 0 : 1;
	data->centers_color = data->config.black_white == 1 ? 0 : 0xFFFFFF;
	data->background_color = data->config.black_white == 1 ? 0xFFFFFF :
		0x404040;
}
