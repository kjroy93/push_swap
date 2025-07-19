/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:13:42 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 15:43:58 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	**args(char *str)
{
	char	**args;

	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	if (!args)
		return (NULL);
	return (args);
}

t_stack	*create_stack(char *str)
{
	char	**numbers;
	t_stack	*stack;
	t_stack	*new;
	int		value;
	int		i;

	stack = NULL;
	i = 0;
	numbers = args(str);
	if (!numbers)
		return (NULL);
	while (numbers[i])
	{
		value = ft_atoi(numbers[i]);
		new = ft_stcnew_node(value);
		if (!new)
		{
			ft_stcclear(&stack);
			return (NULL);
		}
		ft_stcadd_back(&stack, new);
		i++;
	}
	free_split(numbers);
	return (stack);
}
