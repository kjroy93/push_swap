/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 20:34:54 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/28 21:44:01 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	while (current && current->next)
	{
		if (current->number < current->next->number)
		{
			current = current->next;
			continue ;
		}
		else
			return (false);
	}
	return (true);
}

void	mini_sort(t_stack **stack)
{
	int	size;

	size = stack_size(*stack);
	if (size == 2)
		sort_two(stack);
	if (size == 3)
		sort_three(stack);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	a = (*stack)->number;
	b = (*stack)->next->number;
	c = (*stack)->next->next->number;
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

void	sort_two(t_stack **stack)
{
	if (stack_size(*stack) != 2)
		return ;
	if (!check_sorted(*stack))
		sa(stack, true);
}
