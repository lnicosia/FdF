/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:19:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/03 16:19:57 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	draw_axes(t_env *data)
{
	plot_line(new_coord2(0, data->s_height / 2), new_coord2(data->s_width, data->s_height / 2), *data, 0xFFFFFF);
	plot_line(new_coord2(data->s_width / 2, 0), new_coord2(data->s_width / 2, data->s_height), *data, 0xFFFFFF);
}
