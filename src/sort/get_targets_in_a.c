/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets_in_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:41:36 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/25 15:56:52 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_min(t_stack *a)
{
	t_stack	*min;

	min = a;
	while (a)
	{
		if (a->number < min->number)
			min = a;
		a = a->next;
	}
	return (min);
}

static t_stack *find_target_node_in_a(t_stack *a, t_stack *b_node)
{
	t_stack	*current;
	t_stack	*target;
	int		min_above;

	current = a;
	target = NULL;
	min_above = INT_MAX;
	while (current)
	{
		if (current->number > b_node->number && current->number < min_above)
		{
			min_above = current->number;
			target = current;
		}
		current = current->next;
	}
	if (!target)
		target = find_min(a);
	return (target);
}

void	assign_target_in_a(t_stack *a, t_stack *b)
{
	b->target = find_target_node_in_a(a, b);
}
