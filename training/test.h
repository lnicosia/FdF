/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:00:21 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/04 17:55:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

typedef struct		s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
}					t_env;

int		plotLineLow(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr);
int		plotLineHigh(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr);
int		plotLine(int x1, int y1, int x2, int y2, void *mlx_ptr, void *win_ptr);
#endif
