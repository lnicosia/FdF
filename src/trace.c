/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:42:13 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/19 18:27:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "utils.h"
#include "color.h"
#include <stdio.h>

t_coord2	iso_project(t_coord3 c, t_env data)
{
	t_coord2	res;
	t_fcoord3	ftmp;

	ftmp.x = (float)c.x;
	ftmp.y = (float)c.y;
	ftmp.z = (float)c.z * data.scale.z;
	if (data.angle.x != 0)
		x_rotation(&ftmp, data);
	if (data.angle.y != 0)
		y_rotation(&ftmp, data);
	if (data.angle.z != 0)
		z_rotation(&ftmp, data);
	res.x = data.start.x + data.scale.x * (ftmp.x - ftmp.y) * COS_30;
	res.y = data.start.y + data.scale.x * (-(float)(ftmp.z) +
			(ftmp.x + ftmp.y) * SIN_30);
	return (res);
}

t_coord2	para_project(t_coord3 c, t_env data)
{
	t_coord2	res;
	t_fcoord3	ftmp;

	ftmp.x = (float)c.x;
	ftmp.y = (float)c.y;
	ftmp.z = (float)c.z * data.scale.z;
	if (data.angle.x != 0)
		x_rotation(&ftmp, data);
	if (data.angle.y != 0)
		y_rotation(&ftmp, data);
	if (data.angle.z != 0)
		z_rotation(&ftmp, data);
	res.x = data.start.x + data.scale.x * (ftmp.x - ftmp.y);
	res.y = data.start.y + data.scale.x * (-ftmp.z+ ftmp.y);
	return (res);
}

t_fcoord2	fiso_project(t_coord3 c)
{
	t_fcoord2	res;

	res.x = ((float)c.x - (float)c.y) * COS_30;
	res.y = ((float)c.x + (float)c.y) * SIN_30;
	return (res);
}

t_fcoord2	fpara_project(t_coord3 c)
{
	t_fcoord2	res;

	res.x = ((float)c.x - (float)c.y);
	res.y = ((float)c.y);
	return (res);
}

int			get_color(int x, int y, t_env data)
{
	int		z;

	z = data.map[y * data.map_width + x].z;
	if (z <= 0)
		return (0xC3E1FF);
	if (z <= (data.zmax) / data.color_div)
		return (0x344623);
	if (z <= (2 * data.zmax) / data.color_div)
		return (0x7E9F5D);
	if (z <= (3 * data.zmax) / data.color_div)
		return (0xB7CAA4);
	if (z <= (4 * data.zmax) / data.color_div)
		return (0xCBAC83);
	if (z <= (5 * data.zmax) / data.color_div)
		return (0x75552D);
	if (z <= (6 * data.zmax) / data.color_div)
		return (0x583405);
	if (z <= data.zmax)
		return (0xFFFFFF);
	return (0xFFFFFF);
}

void		recenter(t_env *data)
{
	t_fcoord2	center;
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	up = data->fproject[data->project_type](data->map[0]);
	right = data->fproject[data->project_type](data->map[data->map_width - 1]);
	left = data->fproject[data->project_type](data->map[data->map_width *
			(data->map_height - 1)]);
	down = data->fproject[data->project_type](data->map[data->map_width *
			data->map_height - 1]);
	center.x = data->scale.x * (right.x - left.x) / 2 - ft_fabs(left.x)
		* data->scale.x;
	center.y = data->scale.x * (down.y - up.y) / 2 - ft_fabs(up.y)
		* data->scale.x;
	data->start.x = (float)data->s_width / 2 - center.x;
	data->start.y = (float)data->s_height / 2 - center.y;
}

void		set_z_ranges(t_env *data)
{
	data->zmax = (max3(data->map, data->map_height * data->map_width, 'z'));
	printf("zmax: %d\n", data->zmax);
	if (data->zmax != 0)
	{
		data->scale.z = (float)data->map_height / ((float)data->zmax * 10);
		printf("scale.z = %f\n", data->scale.z);
		data->delta.z = (float)data->s_height / (100 * data->zmax *
				data->scale.x);
	}
	ft_putstr(GREEN);
	ft_putstr("[Z SCALED]");
	ft_putendl(RESET);
}

void		set_ranges(t_env *data)
{
	t_fcoord2	right;
	t_fcoord2	left;
	t_fcoord2	up;
	t_fcoord2	down;

	up = data->fproject[data->project_type](data->map[0]);
	right = data->fproject[data->project_type](data->map[data->map_width - 1]);
	left = data->fproject[data->project_type](data->map[data->map_width *
			(data->map_height - 1)]);
	down = data->fproject[data->project_type](data->map[data->map_width *
			data->map_height - 1]);
	data->scale.x = (float)data->s_width / (right.x - left.x);
	data->scale.y = (float)data->s_height / (down.y - up.y);
	data->scale.x = ft_fmin(data->scale.x, data->scale.y) * 0.8;
	data->delta.x = data->scale.x * 10 / 100;
	printf("final scale = %f\n", data->scale.x);
	recenter(data);
	ft_putstr(GREEN);
	ft_putstr("[MAP SCALED]");
	ft_putendl(RESET);
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
				plot_line(data.project[data.project_type](data.map[k], data),
						data.project[data.project_type](data.map[k + 1], data),
						data, get_color(x, y, data));
			if (y < data.map_height - 1)
				plot_line(data.project[data.project_type](data.map[k], data),
						data.project[data.project_type](data.map[k +
							data.map_width], data), data, get_color(x, y, data));
			x++;
			k++;
		}
		y++;
	}
	/*y = data.map_height -1;
	  k = data.map_height * data.map_width - 1;
	  while (y >= 0)
	  {
	  x = data.map_width - 1;
	  while (x >= 0)
	  {
	  if (x > 0)
	  plot_line(data.project[data.project_type](data.map[k], data),
	  data.project[data.project_type](data.map[k - 1], data),
	  data, get_color(x, y, data));
	  if (y > 0)
	  plot_line(data.project[data.project_type](data.map[k], data),
	  data.project[data.project_type](data.map[k -
	  data.map_width], data), data, get_color(x, y, data));
	  x--;
	  k--;
	  }
	  y--;
	  }*/
}
