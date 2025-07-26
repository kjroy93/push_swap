/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:36:57 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/26 18:39:36 by kmarrero         ###   ########.fr       */
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

void	rra(t_stack **a, bool print)
{
	internal_reverse_rotation(a);
	if (print)
		print_instruction("rra");
}

void	rrb(t_stack **b, bool print)
{
	internal_reverse_rotation(b);
	if (print)
		print_instruction("rrb");
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	rra(a, false);
	rrb(b, false);
	if (print)
		print_instruction("rrr");
}
