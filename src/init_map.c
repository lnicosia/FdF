/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:46:12 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 17:01:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "color.h"

static int	parse_str(char *str, t_coord3 *map, t_coord2 c, int size)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[j])
	{
		if (c.x < size)
		{
			map[c.x].x = i;
			map[c.x].y = c.y;
			map[c.x].z = ft_atoi(str + j);
		}
		while (str[j] && str[j] != ' ')
			j++;
		while (str[j] && str[j] == ' ')
			j++;
		c.x++;
		i++;
	}
	return (c.x);
}

t_coord3	*init_map(int height, int width, t_list *r_map)
{
	t_coord3	*map;
	t_coord2	c;
	int			size;
	char		*str;

	size = height * width;
	if (!(map = (t_coord3*)malloc(sizeof(*map) * size)))
		return (NULL);
	c.y = 0;
	c.x = 0;
	while (c.y < height)
	{
		str = r_map->content;
		c.x = parse_str(str, map, c, size);
		r_map = r_map->next;
		c.y++;
	}
	ft_putstr(GREEN);
	ft_putstr("[MAP INITIALIZED]");
	ft_putendl(RESET);
	return (map);
}
