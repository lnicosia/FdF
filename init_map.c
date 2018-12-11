/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:46:12 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/11 15:32:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	parse_str(char *str, t_coord3 *map, int *k, int size)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (*k < size)
		{
			map[*k].x = *k;
			map[*k].y = 0;
			map[*k].z = ft_atoi(str + j);
		}
		while (str[j] && str[j] != ' ')
			j++;
		while (str[j] && str[j] == ' ')
			j++;
		(*k)++;
	}
}

t_coord3	*init_map(int height, int width, t_list *r_map)
{
	t_coord3	*map;
	int			i;
	int			k;
	int			size;
	char		*str;

	size = height * width;
	if (!(map = (t_coord3*)malloc(sizeof(*map) * size)))
		return (NULL);
	k = 0;
	i = 0;
	while (i < height)
	{
		str = r_map->content;
		parse_str(str, map, &k, size);
		r_map = r_map->next;
		i++;
	}
	return (map);
}
