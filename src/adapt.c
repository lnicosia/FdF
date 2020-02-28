/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:27:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/01 12:19:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "color.h"

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
	data->center = center;
	data->start.x = (float)data->config.s_width / 2 - center.x + 100;
	data->start.y = (float)data->config.s_height / 2 - center.y;
	put_log("[MAP CENTERED]", 0);
}

void	set_z_ranges(t_env *data)
{
	data->zmax = cmax3(data->map, data->map_height * data->map_width, 'z');
	data->zmin = cmin3(data->map, data->map_height * data->map_width, 'z');
	data->zrange = data->map[data->zmax].z - data->map[data->zmin].z;
	data->zlimit = ft_max(data->map[data->zmax].z, -data->map[data->zmin].z);
	data->zlimit = ft_max(data->zlimit, data->map_height);
	data->zlimit = ft_max(data->zlimit, data->map_width);
	if (data->zrange != 0)
	{
		data->scale.z = (float)data->map_height / ((float)ft_abs(data->zrange) *
				10);
		data->delta_scale.z = data->scale.z / 10;
	}
	put_log("[Z SCALED]", 0);
}

void	set_ztrans(t_env *data)
{
	if (data->map_width % 2 == 1)
	{
		if (data->map_height % 2 == 1)
			data->ztrans = (float)data->map[data->map_width / 2 + (data->
					map_height / 2) * data->map_width].z;
		else
			data->ztrans = ((float)data->map[data->map_width / 2 + ((data->
			map_height - 1) / 2) * data->map_width].z + (float)data->map[data->
			map_width / 2 + ((data->map_height) / 2) * data->map_width].z) / 2;
	}
	else
	{
		if (data->map_height % 2 == 1)
			data->ztrans = ((float)data->map[(data->map_width - 1) / 2 + (data->
			map_height / 2) * data->map_width].z + (float)data->map[data->
			map_width / 2 + (data->map_height / 2) * data->map_width].z) / 2;
		else
			data->ztrans = ((float)data->map[(data->map_width - 1) / 2 + (data->
			map_height - 1) / 2 * data->map_width].z + (float)data->map[data->
			map_width / 2 + (data->map_height - 1) / 2 * data->map_width].z +
			(float)data->map[(data->map_width - 1) / 2 + data->map_height / 2 *
			data->map_width].z + (float)data->map[data->map_width / 2 + data->
			map_height / 2 * data->map_width].z) / 4;
	}
	data->ztrans *= data->scale.z;
}

void	set_ranges(t_env *data)
{
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
	data->scale.x = (float)(data->config.s_width) / ft_fabs(right.x - left.x);
	data->scale.y = (float)data->config.s_height / ft_fabs(down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.6;
	data->delta_scale.x = data->scale.x * 10 / 150;
	put_log("[MAP SCALED]", 0);
}
