/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:40:42 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/31 17:44:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include "error.h"
# include "libft.h"
# define ISO 0
# define PARA 1
# define FLAT 2
# define PC 3
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

typedef struct	s_config
{
	int				color;
	int				file_color;
	int				debug;
	int				s_height;
	int				s_width;
	int				project_type;
	int				trace_type;
	int				centers;
	int				black_white;
	int				trace;
	int				poly;
	int				underside;
	int				fill;
	int				light;
}				t_config;

typedef struct	s_input_buffers
{
	int	button1;
	int	increase;
	int	decrease;
	int	increase_color;
	int	decrease_color;
	int	color_button;
	int	centers_button;
	int	esc;
	int	a;
}				t_input_buffers;

typedef struct	s_env
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	t_img			img;
	t_coord3		*map;
	t_fcoord3		*rotated_map;
	t_fcoord2		*projected_map;
	t_coord2		*moved_map;
	unsigned int	strings_color;
	unsigned int	menu_color;
	unsigned int	background_color;
	unsigned int	edges_color;
	unsigned int	centers_color;
	unsigned int	picked_color;
	unsigned int	current_color;
	unsigned int	red;
	unsigned int	green;
	unsigned int	blue;
	t_config		config;
	t_input_buffers	input_buffers;
	float			*zbuffer;
	int				map_height;
	int				map_width;
	int				zrange;
	int				zlimit;
	int				*file_colors;
	int				color_div;
	int				norm;
	int				zmax;
	int				zmin;
	float			ztrans;
	float			area;
	float			fzmax;
	float			fzmin;
	float			light_range;
	float			c0_c2;
	float			c1_c2;
	t_fcoord2		center;
	t_fcoord3		zvertices;
	t_coord2		drag_start;
	t_coord2		drag_end;
	t_fcoord3		scale;
	t_coord2		move;
	t_coord2		start;
	t_coord2		delta_move;
	t_fcoord3		delta_scale;
	t_fcoord3		angle;
	t_coord2		(*project[2])(t_coord3, struct s_env);
	t_fcoord2		(*pre_project[4])(t_coord3, struct s_env);
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
int				init_map(int height, int width, t_list *r_map, t_env *data);
void			set_ranges(t_env *data);
void			set_ztrans(t_env *data);
void			scale_map(t_env data);
void			move_map(t_env data);
void			move_map(t_env data);
void			project_map(t_env data);
void			set_z_ranges(t_env *data);
t_coord2		iso_project(t_coord3 c, t_env data);
t_coord2		para_project(t_coord3 c, t_env data);
t_fcoord2		pre_iso_project(t_coord3 c, t_env data);
t_fcoord2		pre_para_project(t_coord3 c, t_env data);
t_fcoord2		pre_flat_project(t_coord3 c, t_env data);
t_fcoord2		pre_pc_project(t_coord3 c, t_env data);
void			center(t_env *data);
void			trace(t_env data);
void			fill_obj(t_env *data);
void			trace_aa(t_env data);
unsigned int	get_color(int x, int y, t_env data);
t_coord2		new_coord2(int x, int y);
t_coord3		new_coord3(int x, int y, int z);
t_fcoord3		new_fcoord3(float x, float y, float z);
int				min3(t_coord3 *map, int size, char mode);
int				max3(t_coord3 *map, int size, char mode);
int				cmin3(t_coord3 *map, int size, char mode);
int				cmax3(t_coord3 *map, int size, char mode);
float			fmin3(t_fcoord3 *map, int size, char mode);
float			fmax3(t_fcoord3 *map, int size, char mode);
void			x_rotation(t_env data);
void			y_rotation(t_env data);
void			z_rotation(t_env data);
void			rotate_map(t_env data);
void			float_map(t_env data);
void			init_cos_data(t_env *data);
void			init_sin_data(t_env *data);
void			set_background(t_env data);
void			middle_of_face(int k, unsigned int color, t_env data);
void			print_centers(t_env data);
void			trace_menu(t_env data);
void			put_strings(t_env data);
void			init_hook(t_env *data);
float			edge(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 p);
void			set_screen(t_env *data);
void			init_data(t_env *data);
int				init_zbuffer(t_env *data);
int				init_arrays(t_env *data);
void			put_log(const char *str, int mode);
void			put_map_size(int height, int width);
void			black_white_mode(t_env *data);
void			clear_zbuffer(t_env *data);
void			fill_triangle(t_fcoord3 v[3], t_env *data);
void			trace_z(t_fcoord3 v[3], t_env *data);

#endif
