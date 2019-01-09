/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:19:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/09 15:02:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	draw_axes(t_env *data)
{
	if (data->config.black_white == 0)
	{
		plot_line(new_coord2(200, data->config.s_height / 2), new_coord2(data->config.s_width, data->config.s_height / 2), *data, 0xFFFFFF);
		plot_line(new_coord2(data->config.s_width / 2 + 100, 0), new_coord2(data->config.s_width / 2 + 100, data->config.s_height), *data, 0xFFFFFF);
	}
	else
	{
		plot_line(new_coord2(200, data->config.s_height / 2), new_coord2(data->config.s_width, data->config.s_height / 2), *data, 0);
		plot_line(new_coord2(data->config.s_width / 2 + 100, 0), new_coord2(data->config.s_width / 2 + 100, data->config.s_height), *data, 0);
	}
}
