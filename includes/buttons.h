/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:52:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/23 14:54:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTONS_H
# define BUTTONS_H

void	draw_button_up(t_coord2 c, t_coord2 size, t_env data);
void	draw_button_pressed(t_coord2 c, t_coord2 size, t_env data);
void	put_black_white_button(t_env data);
void	put_centers_button(t_env data);
void	put_increase_buttons(t_env data);
void	put_color_button(t_env data);
void	put_increase_color_buttons(t_env data);

#endif
