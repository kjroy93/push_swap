/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:08:44 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 15:44:27 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stcnew_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->index = -1;
	new_node->number = value;
	new_node->next = NULL;
	new_node->prev = NULL;
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
	if (!lst || !*lst)
		return ;
	new->next = *lst;
	new->index = -1;
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
