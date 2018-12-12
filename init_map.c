/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:46:12 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/12 17:28:08 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	parse_str(char *str, t_coord3 *map, int k, int size)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[j])
	{
		if (k < size)
		{
			map[k].x = i;
			map[k].y = 0;
			map[k].z = ft_atoi(str + j);
		}
		while (str[j] && str[j] != ' ')
			j++;
		while (str[j] && str[j] == ' ')
			j++;
		i++;
		k++;
	}
	return (k);
}

t_coord3	*init_map(int height, int width, t_list *r_map)
{
	t_coord3	*map;
	int			k;
	int			j;
	int			size;
	char		*str;

	size = height * width;
	if (!(map = (t_coord3*)malloc(sizeof(*map) * size)))
		return (NULL);
	j = 0;
	k = 0;
	while (k < size)
	{
		str = r_map->content;
		k = parse_str(str, map, k, size);
		r_map = r_map->next;
		j++;
	}
	return (map);
}
