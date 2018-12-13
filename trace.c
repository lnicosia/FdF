/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:13 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/13 17:42:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include <stdio.h>

t_coord2	iso_project(t_coord3 c, t_env data)
{
	t_coord2	res;

	res.x = data.start.x + data.scale.x * (c.x - c.y) * cos(0.523599);
	res.y = data.start.y + data.scale.x * (-(float)(c.z * data.scale.z) +
			(c.x + c.y) * sin(0.523599));
	return (res);
}

t_fcoord2	fiso_project(t_coord3 c)
{
	t_fcoord2	res;

	res.x = ((float)c.x - (float)c.y) * cos(0.523599);
	res.y = ((float)c.x + (float)c.y) * sin(0.523599);
	return (res);
}

void		recenter(t_env *data)
{
	t_coord2	center;

	printf("recenter\n");
	center = iso_project(data->map[(data->map_width * data->map_height)
			/ 2], *data);
	printf("center.x = %d\ncenter.y = %d\n", center.x, center.y);
	data->start.x += (float)data->s_width / 2 - center.x;
	data->start.y += (float)data->s_height / 2 - center.y;
	printf("start.x = %d\nstart.y = %d\n", data->start.x, data->start.y);
}

void		set_ranges(t_env *data)
{
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;
	int			zmax;

	up = fiso_project(data->map[0]);
	right = fiso_project(data->map[data->map_width - 1]);
	left = fiso_project(data->map[data->map_width * (data->map_height - 1)]);
	down = fiso_project(data->map[data->map_width * data->map_height - 1]);
	zmax = (max3(data->map, data->map_height * data->map_width, 'z'));
	/*printf("up.x = %f\nup.y = %f\n", up.x, up.y);
	printf("down.x = %f\ndown.y = %f\n", down.x, down.y);
	printf("left.x = %f\nleft.y = %f\n", left.x, left.y);
	printf("right.x = %f\nright.y = %f\n", right.x, right.y);*/
	data->scale.x = (float)data->s_width / (right.x - left.x);
	//printf("scale.x = %f\n", data->scale.x);
	data->scale.y = (float)data->s_height / (down.y - up.y);
	//printf("scale.y = %f\n", data->scale.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.66;
	printf("final scale = %f\n", data->scale.x);
	recenter(data);
	data->scale.z = data->map_width / ((float)zmax * 5);
	//printf("scale.z = %f\n", data->scale.z);
	data->delta.z = 1 / pow(10, ft_count(zmax));
	//printf("zmax = %d\ndelta.z = %f\n", zmax, data->delta.z);
}

void		trace(t_env data)
{
	int	y;
	int	x;
	int	k;

	y = 0;
	k = 0;
	while (y < data.map_height)
	{
		x = 0;
		while (x < data.map_width)
		{
			if (x < data.map_width - 1)
				plot_line(iso_project(data.map[k], data),
						iso_project(data.map[k + 1], data), data);
			if (y < data.map_height - 1)
				plot_line(iso_project(data.map[k], data),
						iso_project(data.map[k + data.map_width], data), data);
			x++;
			k++;
		}
		y++;
	}
}
