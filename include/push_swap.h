/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:14:00 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/20 00:17:56 by kjroy93          ###   ########.fr       */
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
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Stack creation functions
t_stack	*ft_stcnew_node(int value);
t_stack	*ft_stclast(t_stack *lst);
t_stack	*argc_stack_creation(int argc, char **argv);
void	ft_stcadd_back(t_stack **lst, t_stack *new);
void	ft_stcadd_front(t_stack **lst, t_stack *new);
void	ft_stcclear(t_stack **lst);
void	free_split(char **args);

// Parse functions for arguments
char	**args(char *str);
char	*allocate_buffer(int argc, char **argv);
void	copy_args_to_buffer(int argc, char **argv, char *buffer);

// function to check for errors
int		validate_string_arguments(char *arg);
int		main_validation(char **argv);

#endif