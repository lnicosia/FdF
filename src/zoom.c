/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:02:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/08 16:31:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"
#include <stdio.h>

void		center_mouse(t_env *data, int x, int y)
{
	t_fcoord2	center;
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	(void)x;
	(void)y;
	up = data->pre_project[data->project_type](data->map[0]);
	right = data->pre_project[data->project_type](data->map[data->map_width - 1]);
	left = data->pre_project[data->project_type](data->map[data->map_width *
			(data->map_height - 1)]);
	down = data->pre_project[data->project_type](data->map[data->map_width *
			data->map_height - 1]);
	center.x = data->scale.x * (right.x - left.x) / 2 - ft_fabs(left.x)
		* data->scale.x;
	center.y = data->scale.x * (down.y - up.y) / 2 - ft_fabs(up.y)
		* data->scale.x;
	data->start.x = (float)data->s_width / 2 - center.x + 100;
	  data->start.y = (float)data->s_height / 2 - center.y;
	/*data->start.x = (float)data->s_width / 2 - (x * data->scale.x);
	  data->start.y = (float)data->s_height / 2 - (y * data->scale.x);*/
}

void	translate_in(t_env *data, int m_x, int m_y)
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
			data->moved_map[k].x -= m_x;
			data->moved_map[k].y -= m_y;
			x++;
			k++;
		}
		y++;
	}
}

void	translate_out(t_env *data, int m_x, int m_y)
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
			data->moved_map[k].x += m_x;
			data->moved_map[k].y += m_y;
			x++;
			k++;
		}
		y++;
	}
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
	//printf("mouse[x] = %d	mouse[y] = %d\n", x, y);
	//data->delta_scale.x *= data->delta_scale.x < 0 ? -1 : 1;
	data->scale.x += data->delta_scale.x;
	center_mouse(data, x, y);
	project_map(*data);
	scale_map(*data);
	/*translate_in(data, x, y);
	rescale_map(data);
	translate_out(data, x, y);*/
	move_map(*data);
	redraw(data);
}

void	zoom_out(t_env *data, int x, int y)
{
	//printf("mouse[x] = %d	mouse[y] = %d\n", x, y);
	if (data->scale.x - data->delta_scale.x >= 0)
	{
		//data->delta_scale.x *= data->delta_scale.x > 0 ? -1 : 1;
		data->scale.x -= data->delta_scale.x;
		center_mouse(data, x, y);
		project_map(*data);
		scale_map(*data);
		/*translate_in(data, x, y);
		rescale_map(data);
		translate_out(data, x, y);*/
		move_map(*data);
		redraw(data);
	}
}
