/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:52:40 by lnicosia          #+#    #+#             */
/*   Updated: 2018/12/14 16:31:30 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_FUNCTIONS_H
# define USER_FUNCTIONS_H

void	quit(t_env *data);
void	redraw(t_env *data);
void	increase_z(t_env *data);
void	decrease_z(t_env *data);
void	zoom_in(t_env *data);
void	zoom_out(t_env *data);
void	move_up(t_env *data);
void	move_down(t_env *data);
void	move_right(t_env *data);
void	move_left(t_env *data);

#endif
