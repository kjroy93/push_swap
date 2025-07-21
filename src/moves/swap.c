/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:19:17 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/21 18:03:04 by kjroy93          ###   ########.fr       */
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
	first->next = second;
	*stack_operated = second;
}

void	sa(t_stack **a)
{
	swap_internal(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap_internal(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap_internal(a);
	swap_internal(b);
	ft_printf("ss\n");
}
