/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:36:57 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/21 19:14:27 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	internal_reverse_rotation(t_stack **stack_operated)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack_operated || !(*stack_operated) || !(*stack_operated)->next)
		return ;
	first = *stack_operated;
	second = ft_stclast((*stack_operated));
	second->prev->next = NULL;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack_operated = second;
}

void	rra(t_stack **a)
{
	internal_reverse_rotation(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	internal_reverse_rotation(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	internal_reverse_rotation(a);
	internal_reverse_rotation(b);
	ft_printf("rrr\n");
}
