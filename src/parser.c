/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:11:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/30 17:53:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "fcntl.h"
#include "color.h"

int		check_line(char *line, int *line_size)
{
	int	i;

	i = 0;
	*line_size = 0;
	while (line[i])
	{
		if (line[i] && line[i] != ' ')
		{
			(*line_size)++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (0);
}

void	del_map_link(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

int		clear_map(t_list **map)
{
	ft_lstdel(map, del_map_link);
	return (LINE_FORMAT_ERROR);
}

int		parser(t_list **map, char *file, int *map_height, int *map_width)
{
	int		fd;
	int		tmp;
	char	*line;
	t_list	*lst_tmp;

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
		if (!(lst_tmp = ft_lstnew(line, ft_strlen(line) + 1)))
			return (MALLOC_ERROR);
		ft_lstpushback(map, lst_tmp);
		ft_strdel(&line);
	}
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	if (*map_width < 2 || *map_height < 2)
		return (FILE_FORMAT_ERROR);
	put_log("[PARSE OK]", 0);
	put_map_size(*map_height, *map_width);
	return (0);
}
