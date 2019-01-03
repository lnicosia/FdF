/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:46:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/03 15:05:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "color.h"

static int	parse_str(char *str, t_env *data, t_coord2 c, int size)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[j])
	{
		if (c.x < size)
		{
			data->map[c.x].x = i;
			data->map[c.x].y = c.y;
			data->map[c.x].z = ft_atoi(str + j);
			data->colors[c.x] = 0xFFFFFF;
		}
		while (str[j] && str[j] != ' ')
		{
			if (str[j] == ',')
			{
				if (c.x < size)
				{
					j = j + 3;
					data->color = 1;
					data->colors[c.x] = ft_atoi_base(str + j, "0123456789abcdef");
					if (data->colors[c.x] == 0)
						data->colors[c.x] = 0xFFFFFF;
				}
			}
			j++;
		}
		while (str[j] && str[j] == ' ')
			j++;
		c.x++;
		i++;
	}
	return (c.x);
}

int			init_map(int height, int width, t_list *r_map, t_env *data)
{
	t_coord2	c;
	int			size;
	char		*str;

	size = height * width;
	if (!(data->map = (t_coord3*)malloc(sizeof(*(data->map)) * size)))
		return (0);
	c.y = 0;
	c.x = 0;
	while (c.y < height)
	{
		str = r_map->content;
		c.x = parse_str(str, data, c, size);
		r_map = r_map->next;
		c.y++;
	}
	clear_map(&r_map);
	ft_putstr(GREEN);
	ft_putstr("[MAP INITIALIZED]");
	ft_putendl(RESET);
	return (1);
}
