/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:31:26 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 11:41:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		project_map_iso(t_env data)
{
	int		y;
	int		x;
	int		k;
	float	tmp;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.rotated_map[k].x;
			data.projected_map[k].x = (data.rotated_map[k].x -
					data.rotated_map[k].y) * COS_30;
			data.projected_map[k].y = (-data.rotated_map[k].z) + (tmp +
					data.rotated_map[k].y) * SIN_30;
			x++;
			k++;
		}
		y++;
	}
}

void		project_map_para(t_env data)
{
	int		y;
	int		x;
	int		k;
	float	tmp;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.rotated_map[k].x;
			data.projected_map[k].x = (data.rotated_map[k].x -
					data.rotated_map[k].y);
			data.projected_map[k].y = (-data.rotated_map[k].z +
					data.rotated_map[k].y);
			x++;
			k++;
		}
		y++;
	}
}

void		project_map_flat(t_env data)
{
	int		y;
	int		x;
	int		k;
	float	tmp;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.rotated_map[k].x;
			data.projected_map[k].x = data.rotated_map[k].x;
			data.projected_map[k].y = data.rotated_map[k].y;
			x++;
			k++;
		}
		y++;
	}
}

void		project_map_pc(t_env data)
{
	int		y;
	int		x;
	int		k;
	float	tmp;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			tmp = data.rotated_map[k].x;
			if (data.rotated_map[k].z >= data.zmax)
			{
				data.projected_map[k].x = -1;
				data.projected_map[k].y = -1;
			}
			else
			{
				data.projected_map[k].x = (data.rotated_map[k].x -
data.map_width / 2) / (-data.rotated_map[k].z + data.zmax + 1);
				data.projected_map[k].y = (data.rotated_map[k].y -
data.map_height / 2) / (-data.rotated_map[k].z + data.zmax + 1);
			}
			x++;
			k++;
		}
		y++;
	}
}

void		project_map(t_env data)
{
	if (data.config.project_type == ISO)
		project_map_iso(data);
	else if (data.config.project_type == PARA)
		project_map_para(data);
	else if (data.config.project_type == FLAT)
		project_map_flat(data);
	else if (data.config.project_type == PC)
		project_map_pc(data);
}
