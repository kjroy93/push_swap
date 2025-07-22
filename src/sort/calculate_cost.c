/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:36:40 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/22 21:12:56 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	calculate_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

int	calculate_total_moves(int cost_a, int cost_b)
{
	int	remainer;
	int	common;

	if ((cost_a >= 0 && cost_b >= 0) || cost_a <= 0 && cost_b <= 0)
	{
		if (abs(cost_a) < abs(cost_b))
			
	}
}