/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:36:39 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/25 01:14:10 by kjroy93          ###   ########.fr       */
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

static void	operations(t_stack **a, t_stack **b)
{
	t_move	move;
	int		size;

	prepare_stacks(*a, *b);
	pb(a, b, true);
	if (*b)
		ft_printf("Esto se ha movido a b: %d\n", (*b)->number);
	pb(a, b, true);
	if (*b && (*b)->next)
		ft_printf("Esto se ha movido a b: %d\n", (*b)->number);
	size = stack_size(*a);
	while (size > 3)
	{
		prepare_stacks(*a, *b);
		move = find_best_move(*a, *b);
		move_nodes(a, b, &move);
		size--;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack	*current;
	char	**arguments;
	int		count;

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
	stack_b = NULL;
	operations(&stack_a, &stack_b);
	current = stack_b;
	while (current)
	{
		ft_printf("%d\n", current->number);
		current = current->next;
	}
	count = get_instruction_count();
	ft_printf("Instructions: %d\n", count);
	return (0);
}
