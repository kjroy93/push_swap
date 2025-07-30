/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_targets_in_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:21:31 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/28 19:24:25 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_max(t_stack *b)
{
	t_stack	*max;

	max = b;
	while (b)
	{
		if (b->number > max->number)
			max = b;
		b = b->next;
	}
	return (max);
}

static t_stack	*find_target_node(t_stack *a_node, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	int		max_below;

	max_below = INT_MIN;
	current = b;
	target = NULL;
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

void	assign_targets(t_stack *a, t_stack *b)
{
	while (a)
	{
		a->target = find_target_node(a, b);
		a = a->next;
	}
}
