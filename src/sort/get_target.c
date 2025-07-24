/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:22:56 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/25 00:38:00 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*find_max(t_stack *b)
{
	t_stack *max;

	max = b;
	while (b)
	{
		if (b->number > max->number)
			max = b;
		b = b->next;
	}
	return (max);
}


// Finds the best target for node A in stack B, following the logic: 
// The closest smaller number, or the maximum if no smaller exists.
t_stack	*find_target_node(t_stack *a_node, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	int		max_below;

	current = b;
	target = NULL;
	max_below = INT_MIN;
	while (current)
	{
		if (current->number < a_node->number && current->number > max_below)
		{
			max_below = current->number;
			target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_max(b);
	return (target);
}

// Asign targets from nodes in stack a -> to nodes in stack b
void	assign_targets(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->target = find_target_node(a, b);
		a = a->next;
	}
}

void	update_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}
