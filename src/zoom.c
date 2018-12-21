/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:02:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/21 20:21:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "user_functions.h"
#include <stdio.h>

void	zoom_in(t_env *data, int x, int y)
{
	t_coord2	center1;
	t_coord2	center2;

	(void)x;
	(void)y;
	center1.x = (data->moved_map[data->map_width - 1].x - data->moved_map[data->map_width * (data->map_height -1)].x) / 2 + data->start.x;
	center1.y = (data->moved_map[data->map_width * data->map_height - 1].y - data->moved_map[0].y) / 2 + data->start.y;
	printf("center1[x] = %d	center1[y] = %d\n", center1.x, center1.y);
	data->scale.x += data->delta_scale.x;
	//set_ranges(data);
	project_map(*data);
	scale_map(*data);
	center2.x = (float)data->s_width / 2 - data->start.x;
	center2.y = (float)data->s_height / 2 - data->start.y;
	printf("center2[x] = %d	center2[y] = %d\n", center2.x, center2.y);
	/*printf("center x = %d	center y = %d\n", );
	  data->start.x += data->start.x - x;
	  data->start.y += data->start.y - y;*/
	//recenter(data);
	center_map(*data);
	redraw(data);
}

void	zoom_out(t_env *data, int x, int y)
{
	t_coord2	center1;
	//t_coord2	center2;

	(void)x;
	(void)y;
	if (data->scale.x - data->delta_scale.x >= 0)
	{
		center1.x = (data->moved_map[data->map_width - 1].x - data->moved_map[data->map_width * (data->map_height -1)].x) / 2;
		center1.y = (data->moved_map[data->map_width * data->map_height - 1].y - data->moved_map[0].y) / 2;
		printf("center1[x] = %d	center1[y] = %d\n", center1.x, center1.y);
		data->scale.x -= data->delta_scale.x;
		/*data->start.x += data->s_width / 2;
		  data->start.y += data->s_height / 2;*/
		project_map(*data);
		scale_map(*data);
		//recenter(data);
		center_map(*data);
		redraw(data);
	}
}
