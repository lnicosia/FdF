/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:46:12 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/10 18:06:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	fill_map(char *str, t_coord3 *map, int *k, int i)
{
	int	j;

	j = 0;
	while (str[j])
	{
		map[*k].x = *k;
		map[*k].y = i;
		map[*k].z = ft_atoi(str + j);
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
	char		*str;

	if (!(map = (t_coord3*)malloc(sizeof(*map) * height * width)))
		return (NULL);
	k = 0;
	i = 0;
	while (i < height)
	{
		str = r_map->content;
		fill_map(str, map, &k, i);
		r_map = r_map->next;
		i++;
	}
	return (map);
}
