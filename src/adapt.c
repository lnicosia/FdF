/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:27:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/28 15:16:10 by lnicosia         ###   ########.fr       */
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
	center.x = data->scale.x * (right.x + left.x) / 2;
	center.y = data->scale.x * (down.y + up.y) / 2;
	data->start.x = (float)data->config.s_width / 2 - center.x + 100;
	data->start.y = (float)data->config.s_height / 2 - center.y;
}

void	set_z_ranges(t_env *data)
{
	printf("zrange: %d\n", data->zrange);
	if (data->zrange != 0)
	{
		data->scale.z = (float)data->map_height / ((float)ft_abs(data->zrange) * 10);
		printf("scale.z = %f\n", data->scale.z);
		data->delta_scale.z = (float)data->config.s_height / (100 * ft_abs(data->zrange)
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

	//data->zrange = (max3(data->map, data->map_height * data->map_width, 'z') - min3(data->map, data->map_height * data->map_width, 'z'));
	data->zmax = cmax3(data->map, data->map_height * data->map_width, 'z');
	data->zmin = cmin3(data->map, data->map_height * data->map_width, 'z');
	data->zrange = data->map[data->zmax].z - data->map[data->zmin].z;
	data->zlimit = ft_max(data->map[data->zmax].z, -data->map[data->zmin].z);
	data->zlimit = ft_max(data->zlimit, data->map_height);
	data->zlimit = ft_max(data->zlimit, data->map_width);
	printf("zmax = %d\n", data->map[data->zmax].z);
	up = data->pre_project[data->config.project_type](data->map[0], *data);
	right = data->pre_project[data->config.project_type](data->map[data->
			map_width - 1], *data);
	left = data->pre_project[data->config.project_type](data->map[data->
			map_width *
			(data->map_height - 1)], *data);
	down = data->pre_project[data->config.project_type](data->map[data->
			map_width *
			data->map_height - 1], *data);
	printf("right.x = %f\n", right.x);
	printf("left.x = %f\n", left.x);
	printf("down.y = %f\n", down.y);
	printf("up.y = %f\n", up.y);
	printf("right - left = %f\n", right.x - left.x);
	printf("down - up = %f\n", down.y - up.y);
	data->scale.x = (float)(data->config.s_width) / (right.x - left.x);
	data->scale.y = (float)data->config.s_height / (down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.6;
	//data->scale.x = 1;
	data->delta_scale.x = data->scale.x * 10 / 150;
	printf("final scale = %f\n", data->scale.x);
	printf("zlimit = %d\n", data->zlimit);
	put_log("[MAP SCALED]", 0);
}
