/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_line_z.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:09:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/21 12:49:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_POLY_UTILS_H
# define FILL_POLY_UTILS_H

void	plot_line_z(t_coord2 c[2], t_env data, int color, t_fcoord3 vertices[3]);
int		min_3(int a, int b, int c);
int		max_3(int a, int b, int c);
int		bottom_vertex(float a, float b, float c, float d);
int		top_vertex(float a, float b, float c, float d);
float	edge(t_fcoord3 c0, t_fcoord3 c1, t_fcoord3 p);
void	flush_zbuffer(t_env *data);

#endif
