/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:13:42 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/25 20:29:05 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_stack	*create_stack(char **arguments)
{
	t_stack	*stack;
	t_stack	*new;
	int		value;
	int		i;

	stack = NULL;
	i = 0;
	while (arguments[i])
	{
		value = ft_atoi(arguments[i]);
		new = ft_stcnew_node(value);
		if (!new)
		{
			ft_stcclear(&stack);
			free_split(arguments);
			return (NULL);
		}
		ft_stcadd_back(&stack, new);
		i++;
	}
	return (stack);
}
