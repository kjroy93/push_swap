/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:36:39 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/23 01:06:29 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	**validations(int argc, char **argv)
{
	if (argc == 2)
		return (parse_single_argument(argv[1]));
	else
		return (parse_multiple_arguments(argc, argv));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*current;
	char	**arguments;

	if (!argv || argc == 1 || only_whitespaces(argv))
		return (ft_printf("%s\n", "Error"), 0);
	arguments = validations(argc, argv);
	if (!arguments)
		return (ft_printf("%s\n", "Error"), 0);
	stack_a = create_stack(arguments);
	if (!stack_a)
	{
		free_split(arguments);
		return (0);
	}
	current = stack_a;
	while (current != NULL)
	{
		ft_printf("%d ", current->number);
		current = current->next;
	}
	ft_stcclear(&stack_a);
	free_split(arguments);
	return (0);
}
