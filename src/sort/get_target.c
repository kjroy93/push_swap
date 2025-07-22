/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:22:56 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/22 20:55:42 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	distance(int a, int b)
{
	if (a > b)
		return (a - b);
	else
		return (b - a);
}

static t_stack	*find_max(t_stack *b)
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
static t_stack	*find_target_node(t_stack *a_node, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	int	min_diff;
	int	diff;

	target = NULL;
	min_diff = INT_MAX;
	current = b;
	while(current)
	{
		if (current->number > a_node->number)
		{
			diff = distance(a_node->number, current->number);
			if (diff < min_diff)
			{
				min_diff = diff;
				target = current;
			}
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
