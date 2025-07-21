/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:26:54 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/21 17:55:26 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	internal_push(t_stack **stack_operated, t_stack **target)
{
	t_stack	*a;
	t_stack	*b;

	if (!stack_operated || !*stack_operated)
		return ;
	a = (*stack_operated);
	b = a->next;
	if (b)
		b->prev = NULL;
	(*stack_operated) = b;
	ft_stcadd_front(target, a);
}

void	pb(t_stack **a, t_stack **b)
{
	internal_push(a, b);
	ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	internal_push(b, a);
	ft_printf("pa\n");
}
