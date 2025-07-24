/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:34:54 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/25 00:13:01 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack);
	b = (*stack)->next->number;
	c = (*stack)->next->next->next;
	if (a > b && b < c && a < c)
		sa(stack, true);
	else if (a > b && b > c)
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if (a > b && b < c && a > c)
		ra(stack, true);
	else if (a < b && b > c && a < c)
	{
		sa(stack, true);
		ra(stack, true);
	}
	else if (a < b && b > c && a > c)
		rra(stack, true);
}
