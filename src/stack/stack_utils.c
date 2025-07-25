/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:08:44 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/25 16:57:29 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stcnew_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->pos = -1;
	new_node->number = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target = NULL;
	return (new_node);
}

void	ft_stcadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_stcadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	new->prev = NULL;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_stcclear(t_stack **lst)
{
	t_stack	*temp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		(*lst) = NULL;
		*lst = temp;
	}
}

void	prepare_stacks(t_stack *a, t_stack *b, char target)
{
	if (target == 'b')
	{
		update_positions(a);
		update_positions(b);
		assign_targets(a, b);
	}
	else if (target == 'a')
	{
		update_positions(a);
		update_positions(b);
		assign_target_in_a(a, b);
	}
}
