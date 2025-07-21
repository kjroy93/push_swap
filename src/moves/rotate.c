/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:04:43 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/21 18:54:26 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void internal_rotate(t_stack **stack_operated)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_operated || !(*stack_operated) || !(*stack_operated)->next)
		return ;
	first = *stack_operated;
	second = ft_stclast((*stack_operated));
	*stack_operated = first->next;
	(*stack_operated)->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = NULL;
}

void	ra(t_stack **a)
{
	internal_rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	internal_rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	internal_rotate(a);
	internal_rotate(b);
	ft_printf("rr\n");
}
