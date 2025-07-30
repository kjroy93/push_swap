/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:51:34 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/30 20:38:06 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	internal_rotate(t_stack **stack_operated)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_operated || !(*stack_operated) || !(*stack_operated)->next)
		return ;
	first = (*stack_operated);
	second = ft_stclast((*stack_operated));
	(*stack_operated) = first->next;
	(*stack_operated)->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = NULL;
}

void	ra(t_stack **a, bool print)
{
	internal_rotate(a);
	if (print)
		print_instruction("ra");
}

void	rb(t_stack **b, bool print)
{
	internal_rotate(b);
	if (print)
		print_instruction("rb");
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	ra(a, false);
	rb(b, false);
	if (print)
		print_instruction("rr");
}
