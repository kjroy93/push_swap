/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 18:07:44 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/26 18:30:04 by kmarrero         ###   ########.fr       */
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

void	pb(t_stack **a, t_stack **b, bool print)
{
	internal_push(a, b);
	if (print)
		print_instruction("pb");
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	internal_push(b, a);
	if (print)
		print_instruction("pa");
}
