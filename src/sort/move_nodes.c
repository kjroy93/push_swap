/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:33:41 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/23 22:24:41 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_stacks(t_stack *a, t_stack *b)
{
	update_positions(a);
	update_positions(b);
	assign_targets(a, b);	
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_move *move)
{
	while (move->cost.cost_a > 0 && move->cost.cost_b > 0)
	{
		rr(a, b);
		move->cost.cost_a--;
		move->cost.cost_b--;
	}
	while (move->cost.cost_a < 0 && move->cost.cost_b < 0)
	{
		rrr(a, b);
		move->cost.cost_a++;
		move->cost.cost_b++;
	}
}

static void rotate_one_stack(t_stack **a, t_stack **b, t_move *move)
{
	while (move->cost.cost_a > 0)
	{
		ra(a);
		move->cost.cost_a--;
	}
	while (move->cost.cost_a < 0)
	{
		rra(a);
		move->cost.cost_a++;
	}
	while (move->cost.cost_b > 0)
	{
		rb(b);
		move->cost.cost_b--;
	}
	while (move->cost.cost_b < 0)
	{
		rrb(b);
		move->cost.cost_b++;
	}
}

void	move_nodes(t_stack **a, t_stack **b, t_move *move)
{
	reverse_rotate_both(a, b, move);
	rotate_one_stack(a, b, move);
	pb(a, b);
}
