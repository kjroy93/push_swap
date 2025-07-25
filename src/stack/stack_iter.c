/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:10:43 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/25 14:06:23 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stclast(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	ft_stcsize(t_stack *lst)
{
	t_stack	*tmp;
	int		size;

	size = 0;
	tmp = lst;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

void	give_node_a_position(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	update_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}
