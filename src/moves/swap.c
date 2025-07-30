/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:02:59 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/30 20:38:33 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	internal_swap(t_stack **stack_operated)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_operated || !(*stack_operated) || !(*stack_operated)->next)
		return ;
	first = (*stack_operated);
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	(*stack_operated) = second;
}

void	sa(t_stack **a, bool print)
{
	internal_swap(a);
	if (print)
		print_instruction("sa");
}

void	sb(t_stack **b, bool print)
{
	internal_swap(b);
	if (print)
		print_instruction("sb");
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		print_instruction("ss");
}
