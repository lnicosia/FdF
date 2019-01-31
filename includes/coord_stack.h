/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_stack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:20:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/31 17:46:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_STACK_H
# define COORD_STACK_H
# include "utils.h"

typedef struct	s_coord_stack
{
	t_coord2				c;
	struct s_coord_stack	*next;
}				t_coord_stack;

void			push_stack(t_coord_stack **stack, int x, int y);
int				pop_stack(t_coord_stack **stack, int *x, int *y);

#endif
