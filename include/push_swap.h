/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:14:00 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/23 22:03:13 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <limits.h>

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
	int cost_a;
	int cost_b;
} 	t_cost;

typedef struct s_move
{
	int		total_moves;
	t_stack *node;	// Node of stack A
	t_cost	cost;
} 	t_move;

// Stack creation functions
t_stack	*create_stack(char **arguments);
t_stack	*ft_stcnew_node(int value);
t_stack	*ft_stclast(t_stack *lst);
void	ft_stcadd_front(t_stack **lst, t_stack *new);
void	ft_stcadd_back(t_stack **lst, t_stack *new);
void	ft_stcclear(t_stack **lst);
void	free_split(char **args);

// Functions to parse the arguments from main
char	**parse_multiple_arguments(int argc, char **argv);
char	**parse_single_argument(char *arg);

// Function to check for errors
int		main_validation(char **argv);
int		only_whitespaces(char **argv);

void	assign_targets(t_stack *a, t_stack *b);
t_move 	find_best_move(t_stack *a, t_stack *b);
void	update_positions(t_stack *stack);
void	move_nodes(t_stack **a, t_stack **b, t_move *move);
void	prepare_stacks(t_stack *a, t_stack *b);
int		stack_size(t_stack *stack);

// Instructions to move the nodes in the stacks
void	rra(t_stack **a);
void	ra(t_stack **a);
void	sa(t_stack **a);
void	rrb(t_stack **b);
void	rb(t_stack **b);
void	sb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);

#endif