/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:33:41 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/25 16:51:35 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_move *move)
{
	while (move->cost.cost_a > 0 && move->cost.cost_b > 0)
	{
		rr(a, b, true);
		move->cost.cost_a--;
		move->cost.cost_b--;
	}
	while (move->cost.cost_a < 0 && move->cost.cost_b < 0)
	{
		rrr(a, b, true);
		move->cost.cost_a++;
		move->cost.cost_b++;
	}
}

static void rotate_one_stack(t_stack **a, t_stack **b, t_move *move)
{
	while (move->cost.cost_a > 0)
	{
		ra(a, true);
		move->cost.cost_a--;
	}
	while (move->cost.cost_a < 0)
	{
		rra(a, true);
		move->cost.cost_a++;
	}
	while (move->cost.cost_b > 0)
	{
		rb(b, true);
		move->cost.cost_b--;
	}
	while (move->cost.cost_b < 0)
	{
		rrb(b, true);
		move->cost.cost_b++;
	}
}

void	move_nodes(t_stack **a, t_stack **b, t_move *move, char target)
{
	if (target == 'b')
	{
		reverse_rotate_both(a, b, move);
		rotate_one_stack(a, b, move);
		pb(a, b, true);
	}
	else if (target == 'a')
	{
		reverse_rotate_both(a, b, move);
		rotate_one_stack(a, b, move);
		pa(a, b, true);
	}
}
