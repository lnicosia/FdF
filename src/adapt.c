/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adapt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:27:47 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/29 13:17:20 by lnicosia         ###   ########.fr       */
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
	data->center = center;
	data->start.x = (float)data->config.s_width / 2 - center.x + 100;
	data->start.y = (float)data->config.s_height / 2 - center.y;
}

void	set_z_ranges(t_env *data)
{
	data->zmax = cmax3(data->map, data->map_height * data->map_width, 'z');
	data->zmin = cmin3(data->map, data->map_height * data->map_width, 'z');
	data->zrange = data->map[data->zmax].z - data->map[data->zmin].z;
	data->zlimit = ft_max(data->map[data->zmax].z, -data->map[data->zmin].z);
	data->zlimit = ft_max(data->zlimit, data->map_height);
	data->zlimit = ft_max(data->zlimit, data->map_width);
	printf("zmax = %d\n", data->map[data->zmax].z);
	printf("zrange: %d\n", data->zrange);
	if (data->zrange != 0)
	{
		data->scale.z = (float)data->map_height / ((float)ft_abs(data->zrange) * 10);
		printf("scale.z = %f\n", data->scale.z);
		data->delta_scale.z = (float)data->config.s_height / (5000 * ft_abs(data->zrange));
		printf("delta.scale.z = %f\n", data->delta_scale.z);
	}
	put_log("[Z SCALED]", 0);
}

void	set_ztrans(t_env *data)
{
	if (data->map_width % 2 == 1)
	{
		if (data->map_height % 2 == 1)
		{
			printf("impaire x impaire\n");
			data->ztrans = data->map[data->map_width / 2 + (data->map_height / 2) * data->map_width].z;
		}
		else
		{
			printf("impaire x paire\n");
			data->ztrans = (data->map[data->map_width / 2 + ((data->map_height - 1) / 2) * data->map_width].z + data->map[data->map_width / 2 + ((data->map_height) / 2) * data->map_width].z) / 2;
		}
	}
	else
	{
		if (data->map_height % 2 == 1)
		{
			printf("paire x impaire\n");
			data->ztrans = (data->map[(data->map_width - 1) / 2 + (data->map_height / 2) * data->map_width].z + data->map[data->map_width / 2 + (data->map_height / 2) * data->map_width].z) / 2;
		}
		else
		{
			printf("paire x paire\n");
			data->ztrans = (data->map[(data->map_width - 1) / 2 + (data->map_height / 2) * data->map_width].z + data->map[data->map_width / 2 + (data->map_height / 2) * data->map_width].z + data->map[data->map_width / 2 + ((data->map_height - 1) / 2) * data->map_width].z + data->map[(data->map_width - 1) / 2 + ((data->map_height - 1) / 2) * data->map_width].z) / 4;
		}
	}
	printf("[%d][%d]\n[%d][%d]\n", (data->map_width - 1) / 2 + ((data->map_height - 1) / 2) * data->map_width, data->map_width / 2 + ((data->map_height - 1) / 2) * data->map_width, (data->map_width - 1) / 2 + (data->map_height / 2) * data->map_width, data->map_width / 2 + (data->map_height / 2) * data->map_width);
	printf("z trans = %f\n", data->ztrans);
}

void	set_ranges(t_env *data)
{
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	printf("scale.z = %f\n", data->scale.z);
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
	data->scale.x = (float)(data->config.s_width) / ft_fabs(right.x - left.x);
	data->scale.y = (float)data->config.s_height / ft_fabs(down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.6;
	data->delta_scale.x = data->scale.x * 10 / 150;
	printf("final scale = %f\n", data->scale.x);
	printf("zlimit = %d\n", data->zlimit);
	put_log("[MAP SCALED]", 0);
}