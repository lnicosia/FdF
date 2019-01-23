/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arrays.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:54:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 14:02:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		init_zbuffer(t_env *data)
{
	int	i;
	int	j;
	int	k;

	if (!(data->zbuffer = (float*)malloc(sizeof(float) * data->config.s_width
					* data->config.s_height)))
		return (0);
	i = 0;
	k = 0;
	while (i < data->config.s_height)
	{
		j = 0;
		while (j < data->config.s_width)
		{
			data->zbuffer[k] = 2147483647;
			j++;
			k++;
		}
		i++;
	}
	return (1);
}

int		init_arrays(t_env *data)
{
	init_zbuffer(data);
	data->file_colors = (int*)malloc(sizeof(int) * data->map_width * data->
			map_height);
	data->rotated_map = (t_fcoord3*)malloc(sizeof(*data->rotated_map) *
			data->map_width * data->map_height);
	data->projected_map = (t_fcoord2*)malloc(sizeof(*data->projected_map) *
			data->map_width * data->map_height);
	data->moved_map = (t_coord2*)malloc(sizeof(*data->moved_map) * data->
			map_width * data->map_height);
	return (1);
}
