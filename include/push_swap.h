/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:14:00 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/28 21:34:03 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				number;
	int				pos;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
}	t_cost;

typedef struct s_move
{
	int		total_moves;
	t_stack	*node;	// Node of stack A
	t_cost	cost;
}	t_move;

// Stack creation functions
t_stack	*create_stack(char **arguments);
t_stack	*ft_stcnew_node(int value);
t_stack	*ft_stclast(t_stack *lst);
void	ft_stcadd_front(t_stack **lst, t_stack *new);
void	ft_stcadd_back(t_stack **lst, t_stack *new);
void	ft_stcclear(t_stack **lst);
int		stack_size(t_stack *stack);
void	free_split(char **args);
void	free_list(t_stack *stack, char **arguments);
void	clear_targets(t_stack **stack);

// Functions to parse the arguments from main
char	**parse_multiple_arguments(int argc, char **argv);
char	**parse_single_argument(char *arg);

// Function to check for errors
int		only_whitespaces(char **argv);
int		main_validations(char **argv);

// Sort the stacks
t_move	find_best_move_to_b(t_stack *a, t_stack *b);
t_move	find_best_move_to_a(t_stack *a, t_stack *b);
void	prepare_stacks(t_stack *a, t_stack *b, char target);
void	assign_targets(t_stack *a, t_stack *b);
void	assign_target_in_a(t_stack *a, t_stack *b);
void	move_nodes(t_stack **a, t_stack **b, t_move *move, char target);
void	update_positions(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort_two(t_stack **stack);
void	align_stack_a(t_stack **a);
void	print_instruction(const char *instr);
bool	check_sorted(t_stack *a);
void	mini_sort(t_stack **stack);
int		calculate_cost(int pos, int size);

// Instructions to move the nodes in the stacks
void	rra(t_stack **a, bool print);
void	ra(t_stack **a, bool print);
void	sa(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rb(t_stack **b, bool print);
void	sb(t_stack **b, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);
void	rr(t_stack **a, t_stack **b, bool print);
void	ss(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
void	pa(t_stack **a, t_stack **b, bool print);

#endif