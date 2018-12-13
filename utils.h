/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:42 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/13 16:31:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "error.h"
# include "libft.h"
# define ISO 400
# define PARA 401

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

typedef struct	s_fcoord2
{
	float	x;
	float	y;
}				t_fcoord2;

typedef struct	s_fcoord3
{
	float	x;
	float	y;
	float	z;
}				t_fcoord3;

typedef struct	s_img
{
	int		bit_per_pixels;
	int		size_line;
	int		endian;
	char	*str;
}				t_img;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img		img;
	t_coord3	*map;
	int			map_height;
	int			map_width;
	int			s_height;
	int			s_width;
	int			project_type;
	t_fcoord3	scale;
	t_coord2	start;
	t_fcoord3	delta;
}				t_env;

int				plot_line(t_coord2 c1, t_coord2 c2, t_env data);
int				key_press(int key, void *param);
int				key_release(int key, void *param);
int				mouse_press(int button, int x, int y, void *param);
int				mouse_release(int button, int x, int y, void *param);
int				mouse_move(int x, int y, void *param);
int				expose(void *param);
int				close_window(void *param);
int				parser(
		t_list **map, char *file, int *map_height, int *map_width);
int				clear_map(t_list **map);
void			del_map_link(void *content, size_t content_size);
t_coord3		*init_map(int height, int width, t_list *r_map);
void			set_ranges(t_env *data);
t_coord2		iso_project(t_coord3 c, t_env data);
t_fcoord2		fiso_project(t_coord3 c);
void			recenter(t_env *data);
void			trace(t_env data);
t_coord2		new_coord2(int x, int y);
t_coord3		new_coord3(int x, int y, int z);
t_fcoord3		new_fcoord3(float x, float y, float z);
int				min3(t_coord3 *map, int size, char mode);
int				max3(t_coord3 *map, int size, char mode);
void			redraw(t_env *data);

#endif
