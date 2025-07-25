/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:36:40 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/25 19:16:25 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_cost(int pos, int size)
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
	int	total;

	// Optimization for rrr or rr
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (abs(cost_a) < abs(cost_b))
			common = abs(cost_a);
		else
			common = abs(cost_b);
		remainer = abs(cost_a - cost_b); // Difference to obtain the not common moves
		total = (common + remainer);
	}
	// You can't use rr or rrr. The pos in the stack is not on the same side
	else
		total = (abs(cost_a) + abs(cost_b));
	return (total + 1);
}

static t_move	get_move_info(t_stack *m_node, int size_a, int size_b, bool from_b)
{
	t_move	move_info;

	move_info.node = m_node;
	if (from_b)
	{
		move_info.cost.cost_a = calculate_cost(m_node->target->pos, size_a);
		move_info.cost.cost_b = calculate_cost(m_node->pos, size_b);
	}
	else
	{
		move_info.cost.cost_a = calculate_cost(m_node->pos, size_a);
		move_info.cost.cost_b = calculate_cost(m_node->target->pos, size_b);
	}
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
	while (tmp)
	{
		current_move = get_move_info(tmp, size_a, size_b, false);
		if (current_move.total_moves < best_move.total_moves)
			best_move = current_move;
		tmp = tmp->next;
	}
	return (best_move);
}

t_move	find_move_to_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	t_move	move;
	int	size_a;

	tmp = b;
	size_a = stack_size(a);
	move = get_move_info(tmp, size_a, 0, true);
	return (move);
}
