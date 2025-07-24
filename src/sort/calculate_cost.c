/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:36:40 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/24 19:40:09 by kjroy93          ###   ########.fr       */
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

static int	calculate_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

static int	calculate_total_moves(int cost_a, int cost_b)
{
	int	remainer;
	int	common;

	// Optimization for rrr or rr
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (abs(cost_a) < abs(cost_b))
			common = abs(cost_a);
		else
			common = abs(cost_b);
		remainer = abs(cost_a - cost_b); // Difference to obtain the not common moves
		return (common + remainer);
	}
	// You can't use rr or rrr. The pos in the stack is not on the same side
	else
		return (abs(cost_a) + abs(cost_b));
}

static t_move	get_move_info(t_stack *node_a, int size_a, int size_b)
{
	t_move	move_info;

	move_info.node = node_a;
	move_info.cost.cost_a = calculate_cost(node_a->pos, size_a);
	move_info.cost.cost_b = calculate_cost(node_a->target->pos, size_b);
	move_info.total_moves = calculate_total_moves(
		move_info.cost.cost_a,
		move_info.cost.cost_b
	);
	return (move_info);
}

t_move find_best_move(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_move	current_move;
	t_move	best_move;
	int		size_a;
	int		size_b;
	
	tmp = a;
	best_move.total_moves = INT_MAX;
	best_move.node = NULL;
	size_a = stack_size(a);
	size_b = stack_size(b);
	while(tmp)
	{
		current_move = get_move_info(tmp, size_a, size_b);
		if (current_move.total_moves < best_move.total_moves)
			best_move = current_move;
		tmp = tmp->next;
	}
	return (best_move);
}
