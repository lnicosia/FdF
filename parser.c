/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:11:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/07 15:53:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "fcntl.h"

static int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
			return (LINE_FORMAT_ERROR);
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

int			parser(t_list **map, char *file)
{
	size_t	line_size;
	int		line_count;
	int		fd;
	char	*line;

	line_count = 0;
	line_size = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (OPEN_ERROR);
	while (get_next_line(fd, &line) > 0)
	{
		if (line_size != 0 && line_size != ft_strlen(line))
			return (LINE_ERROR);
		if (check_line(line) != 0)
			return (clear_map(map));
		line_count++;
		ft_lstpushback(map, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	return (line_count);
}
