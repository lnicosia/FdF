/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_project.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:24:50 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 12:11:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_fcoord2	pre_iso_project(t_coord3 c, t_env data)
{
	t_fcoord2	res;

	(void)data;
	res.x = ((float)c.x - (float)c.y) * COS_30;
	res.y = -((float)c.z * data.scale.z) + ((float)c.x + (float)c.y) * SIN_30;
	return (res);
}

t_fcoord2	pre_para_project(t_coord3 c, t_env data)
{
	t_fcoord2	res;

	(void)data;
	res.x = ((float)c.x - (float)c.y);
	res.y = (-(float)c.z * data.scale.z + (float)c.y);
	return (res);
}

t_fcoord2	pre_flat_project(t_coord3 c, t_env data)
{
	t_fcoord2	res;

	(void)data;
	res.x = (float)c.x;
	res.y = (float)c.y;
	return (res);
}

t_fcoord2	pre_pc_project(t_coord3 c, t_env data)
{
	t_fcoord2	res;

	res.x = (((float)c.x - data.map_width / 2) / (-((float)c.z * data.scale.z + data.ztrans * data.scale.z) + data.map[data.zmax].z + data.zlimit + 1));
	res.y = (((float)c.y - data.map_height / 2) / (-((float)c.z * data.scale.z + data.ztrans * data.scale.z) + data.map[data.zmax].z + data.zlimit + 1));
	return (res);
}
