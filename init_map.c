/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 16:46:12 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/07 19:03:13 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	fill_map(char *str, int **map, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (str[j])
	{
		map[i][k] = ft_atoi(str + j);
		while (str[j] && str[j] != ' ')
			j++;
		while (str[j] && str[j] == ' ')
			j++;
		k++;
	}
}

int		**init_map(int height, int width, t_list *r_map)
{
	int		**map;
	int		i;
	char	*str;

	if (!(map = (int**)malloc(sizeof(*map) * height)))
		return (NULL);
	i = 0;
	while (i < height)
	{
		str = r_map->content;
		if (!(map[i] = (int*)malloc(sizeof(**map) * width)))
			return (NULL);
		fill_map(str, map, i);
		r_map = r_map->next;
		i++;
	}
	return (map);
}
