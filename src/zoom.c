/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:02:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/28 12:29:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"
#include <stdio.h>

void	center_mouse(t_env *data, int x, int y)
{
	t_fcoord2	center;
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	(void)x;
	(void)y;
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

void	rescale_map(t_env *data)
{
	int	y;
	int	x;
	int	k;

	y = 0;
	k = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			data->moved_map[k].x += data->moved_map[k].x * data->delta_scale.x;
			data->moved_map[k].y += data->moved_map[k].y * data->delta_scale.x;
			x++;
			k++;
		}
		y++;
	}
}

void	zoom_in(t_env *data, int x, int y)
{
	data->scale.x += data->delta_scale.x;
	center_mouse(data, x, y);
	project_map(*data);
	scale_map(*data);
	move_map(*data);
	redraw(data);
}

void	zoom_out(t_env *data, int x, int y)
{
	if (data->scale.x - data->delta_scale.x >= 0)
	{
		data->scale.x -= data->delta_scale.x;
		center_mouse(data, x, y);
		project_map(*data);
		scale_map(*data);
		move_map(*data);
		redraw(data);
	}
}
