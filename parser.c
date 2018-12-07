/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:11:58 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/07 12:17:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "libft.h"
#include "fcntl.h"

static int	parse_line(t_list **map, char *line)
{
	int	i;
	int	line_size;

	i = -1;
	line_size = 0;
	while (line[++i])
	{
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
				return (LINE_FORMAT_ERROR);
		while (line[i] == ' ')
			i++;
		line_size++;
		ft_lstadd(map, ft_lstnew(line, line_size));
	}
	return (0);
}

int		parser(t_list **map, char *file)
{
	size_t	line_size;
	int		line_count;
	int		fd;
	char	*line;

	/*if (!(*map = (t_list*)malloc(sizeof(*map))))
		return (MALLOC_ERROR);*/
	line_count = 0;
	line_size = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (OPEN_ERROR);
	while (get_next_line(fd, &line))
	{
		if (line_size != 0 && line_size != ft_strlen(line))
			return (LINE_ERROR);
		parse_line(map, line);
		line_count++;
		//ft_putendl(line);
		ft_strdel(&line);
	}
	if (close(fd) == -1)
		return (CLOSE_ERROR);
	return (line_count);
}
