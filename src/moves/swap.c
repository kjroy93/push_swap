/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:19:17 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/29 01:01:43 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	swap_internal(t_stack **stack_operated)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_operated || !*stack_operated || !(*stack_operated)->next)
		return ;
	first = *stack_operated;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_operated = second;
}

void	sa(t_stack **a, bool print)
{
	swap_internal(a);
	if (print)
		print_instruction("sa");
}

void	sb(t_stack **b, bool print)
{
	swap_internal(b);
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
