/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:00:21 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/07 15:50:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "error.h"
# include "libft.h"

typedef struct	s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		***map;
}				t_env;

typedef struct	s_img
{
	int		bit_per_pixels;
	int		size_line;
	int		endian;
	char	*str;
}				t_img;

typedef struct	s_coord2
{
	int		x;
	int		y;
}				t_coord2;

typedef struct	s_coord3
{
	int		x;
	int		y;
	int		z;
}				t_coord3;

int				plot_line(t_coord2 c1, t_coord2 c2, t_img img);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
int				expose(void *param);
int				close_window(void *param);
int				parser(t_list **map, char *file);
int				clear_map(t_list **map);
void			del_map_link(void *content, size_t content_size);

#endif
