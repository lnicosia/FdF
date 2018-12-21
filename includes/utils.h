/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:42 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/21 12:42:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "error.h"
# include "libft.h"
# define ISO 0
# define PARA 1
# define NORMAL 0
# define AA 1
# define COS_30 0.86602540378
# define SIN_30 0.5

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

typedef struct	s_quad
{
	t_coord2	c1;
	t_coord2	c2;
	t_coord2	c3;
	t_coord2	c4;
}				t_quad;

typedef struct	s_img
{
	int				bit_per_pixels;
	int				size_line;
	int				endian;
	unsigned int	*str;
}				t_img;

typedef struct	s_env
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_img		img;
	t_coord3	*map;
	t_fcoord3	*processed_map;
	t_coord2	*moved_map;
	int			map_height;
	int			map_width;
	int			s_height;
	int			s_width;
	int			project_type;
	int			trace_type;
	int			zmax;
	int			color_div;
	int			zbuffer;
	float		cos_data[21];
	float		sin_data[21];
	t_fcoord3	scale;
	t_coord2	move;
	t_coord2	start;
	t_fcoord3	delta;
	t_fcoord3	angle;
	t_coord2	(*project[2])(t_coord3, struct s_env);
	t_fcoord2	(*fproject[2])(t_coord3);
}				t_env;

void			plot_line(t_coord2 c1, t_coord2 c2, t_env data, int color);
void			plot_line_aa(t_coord2 c1, t_coord2 c2, t_env data, int color);
void			plot_line_low(t_coord2 c1, t_coord2 c2, t_env data, int color);
void			plot_line_low_aa(
		t_coord2 c1, t_coord2 c2, t_env data, int color);
void			plot_line_high(t_coord2 c1, t_coord2 c2, t_env data, int color);
void			plot_line_high_aa(
		t_coord2 c1, t_coord2 c2, t_env data, int color);
int				ipart(float x);
int				round_(float x);
float			fpart(float x);
float			rfpart(float x);
void			fill_img(t_coord2 c, t_env data, int color, float brightness);
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
void			scale_map(t_env data);
void			center_map(t_env data);
void			move_map(t_env data);
void			project_map(t_env data);
void			set_z_ranges(t_env *data);
t_coord2		iso_project(t_coord3 c, t_env data);
t_coord2		para_project(t_coord3 c, t_env data);
t_fcoord2		fiso_project(t_coord3 c);
t_fcoord2		fpara_project(t_coord3 c);
void			recenter(t_env *data);
void			trace(t_env data);
void			trace_aa(t_env data);
t_coord2		new_coord2(int x, int y);
t_coord3		new_coord3(int x, int y, int z);
t_fcoord3		new_fcoord3(float x, float y, float z);
int				min3(t_coord3 *map, int size, char mode);
int				max3(t_coord3 *map, int size, char mode);
void			x_rotation(t_env data);
void			y_rotation(t_env data);
void			z_rotation(t_env data);
void			init_cos_data(t_env *data);
void			init_sin_data(t_env *data);

#endif
