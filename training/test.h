/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:00:21 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/06 11:14:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

typedef struct		s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
}					t_env;

typedef struct		s_img
{
	int		bit_per_pixels;
	int		size_line;
	int		endian;
	char	*str;
}					t_img;

int		plotLine(int x1, int y1, int x2, int y2, t_img img);

#endif
