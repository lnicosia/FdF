/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:16:24 by lnicosia          #+#    #+#             */
/*   Updated: 2019/01/07 17:07:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "coord_stack.h"

int		stack_size(t_coord_stack *stack)
{
	int	size;

	size = 0;
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	push_stack(t_coord_stack **stack, int x, int y)
{
	t_coord_stack	*new;

	if (!(new = (t_coord_stack*)malloc(sizeof(*new))))
		return ;
	new->c = new_coord2(x, y);
	new->next = *stack;
	*stack = new;
}

int		pop_stack(t_coord_stack **stack, int *x, int *y)
{
	t_coord_stack	*tmp;

	if (stack_size(*stack) < 1)
		return (0);
	*x = (*stack)->c.x;
	*y = (*stack)->c.y;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
	return (1);
}
