/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:27:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/24 16:58:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "color.h"
#include <stdio.h>

void	center(t_env *data)
{
	t_fcoord2	center;
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	up = data->pre_project[data->config.project_type](data->map[0], *data);
	right = data->pre_project[data->config.project_type](data->map[data->
			map_width - 1], *data);
	left = data->pre_project[data->config.project_type](data->map[data->
			map_width *
			(data->map_height - 1)], *data);
	down = data->pre_project[data->config.project_type](data->map[data->
			map_width *
			data->map_height - 1], *data);
	center.x = data->scale.x * (right.x - left.x) / 2 - ft_fabs(left.x)
		* data->scale.x;
	center.y = data->scale.x * (down.y - up.y) / 2 - ft_fabs(up.y)
		* data->scale.x;
	data->start.x = (float)data->config.s_width / 2 - center.x + 100;
	data->start.y = (float)data->config.s_height / 2 - center.y;
}

void	set_z_ranges(t_env *data)
{
	printf("zmax: %d\n", data->zmax);
	if (data->zmax != 0)
	{
		data->scale.z = (float)data->map_height / ((float)ft_abs(data->zmax) * 10);
		printf("scale.z = %f\n", data->scale.z);
		data->delta_scale.z = (float)data->config.s_height / (100 * ft_abs(data->zmax)
				* data->scale.x);
		printf("delta.scale.z = %f\n", data->delta_scale.z);
	}
	put_log("[Z SCALED]", 0);
}

void	set_ranges(t_env *data)
{
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	//data->zmax = (max3(data->map, data->map_height * data->map_width, 'z'));
	data->zmax = (max3(data->map, data->map_height * data->map_width, 'z') - min3(data->map, data->map_height * data->map_width, 'z'));
	data->zlimit = data->zmax + 1;
	up = data->pre_project[data->config.project_type](data->map[0], *data);
	right = data->pre_project[data->config.project_type](data->map[data->
			map_width - 1], *data);
	left = data->pre_project[data->config.project_type](data->map[data->
			map_width *
			(data->map_height - 1)], *data);
	down = data->pre_project[data->config.project_type](data->map[data->
			map_width *
			data->map_height - 1], *data);
	data->scale.x = (float)data->config.s_width / (right.x - left.x);
	data->scale.y = (float)data->config.s_height / (down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.6;
	data->delta_scale.x = data->scale.x * 10 / 100;
	printf("final scale = %f\n", data->scale.x);
	put_log("[MAP SCALED]", 0);
}
