/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 20:10:43 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:09:32 by kmarrero         ###   ########.fr       */
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
