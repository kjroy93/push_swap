/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:36:39 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/25 20:32:59 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	**validations(int argc, char **argv)
{
	if (!argv || argc == 1 || only_whitespaces(argv))
		return (NULL);
	if (argc == 2)
		return (parse_single_argument(argv[1]));
	else
		return (parse_multiple_arguments(argc, argv));
}

static void phase_2(t_stack **a, t_stack **b)
{
	t_move	move;
	int		size;

	size = stack_size(*b);
	while (size > 0)
	{
		prepare_stacks(*a, *b, 'a');
		move = find_move_to_a(*a, *b);
		move_nodes(a, b, &move, 'a');
		size--;
	}
	update_positions(*a);
	clear_targets(a);
	size = stack_size(*a);
	align_stack_a(a);
}

static void phase_1(t_stack **a, t_stack **b)
{
	t_move	move;
	int		size;

	prepare_stacks(*a, *b, 'b');
	pb(a, b, true);
	pb(a, b, true);
	size = stack_size(*a);
	while (size > 3)
	{
		prepare_stacks(*a, *b, 'b');
		move = find_best_move(*a, *b);
		move_nodes(a, b, &move, 'b');
		size--;
	}
	sort_three(a);
	clear_targets(a);
	clear_targets(b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	char	**arguments;
	int		count;

	arguments = validations(argc, argv);
	if (!arguments)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	stack_a = create_stack(arguments);
	if (!stack_a)
	{
		ft_printf("%s\n", "Error");
		return (0);
	}
	stack_b = NULL;
	phase_1(&stack_a, &stack_b);
	phase_2(&stack_a, &stack_b);
	count = get_instruction_count();
	ft_printf("Instructions: %d\n", count);
	free_split(arguments);
	ft_stcclear(&stack_a);
	return (0);
}
