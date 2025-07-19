/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:36:39 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/20 00:40:31 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*current;
	
	if (!argv || argc == 1)
		return (ft_printf("%s\n", "Error"), 0);
	if (argc == 2)
	{
		if (validate_string_arguments(argv[1]))
			return (ft_printf("%s\n", "Error"), 0);
	}
	else
	{
		if (main_validation(argv + 1))
			return (ft_printf("%s\n", "Error"), 0);
	}
	stack_a = argc_stack_creation(argc, argv);
	if (!stack_a)
		return (0);
	current = stack_a;
	while (current != NULL)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_stcclear(&stack_a);
	return (0);
}
