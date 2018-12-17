/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:11:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/17 17:00:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "fcntl.h"
#include "color.h"

static int	check_line(char *line, int *line_size)
{
	int	i;

	i = 0;
	*line_size = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i])
	{
		while (line[i] && line[i] != ' ')
		{
			if (line[i] != '-' && (line[i] < '0' || line[i] > '9'))
				return (LINE_FORMAT_ERROR);
			i++;
		}
		while (line[i] && line[i] == ' ')
			i++;
		(*line_size)++;
	}
	return (0);
}

void		del_map_link(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

int			clear_map(t_list **map)
{
	ft_lstdel(map, del_map_link);
	return (LINE_FORMAT_ERROR);
}

int			parser(t_list **map, char *file, int *map_height, int *map_width)
{
	int		fd;
	int		tmp;
	char	*line;

	*map_height = 0;
	*map_width = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (OPEN_ERROR);
	while (get_next_line(fd, &line) > 0)
	{
		if (check_line(line, &tmp) != 0)
			return (clear_map(map));
		if (*map_width != 0 && tmp != *map_width)
			return (LINE_ERROR);
		*map_width = tmp;
		(*map_height)++;
		ft_lstpushback(map, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	ft_putstr(GREEN);
	ft_putstr("[PARSE OK]");
	ft_putendl(RESET);
	return (0);
}
