/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:13:42 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/20 00:07:33 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static t_stack	*create_stack(char *str)
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

t_stack	*argc_stack_creation(int argc, char **argv)
{
	t_stack	*stack_a;
	char	*buffer;

	if (argc == 2)
	{
		stack_a = create_stack(argv[1]);
		if (!stack_a)
			return (NULL);
	}
	else
	{
		buffer = allocate_buffer(argc, argv);
		ft_printf("%s", buffer);
		copy_args_to_buffer(argc, argv, buffer);
		stack_a = create_stack(buffer);
		if (!stack_a)
			return (NULL);
		free(buffer);
	}
	return (stack_a);
}
