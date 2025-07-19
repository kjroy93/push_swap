/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:14:00 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 18:15:06 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

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
t_stack	*create_stack(char *str);
void	ft_stcadd_back(t_stack **lst, t_stack *new);
void	ft_stcadd_front(t_stack **lst, t_stack *new);
void	ft_stcclear(t_stack **lst);
void	free_split(char **args);

// Parse functions for arguments
void	copy_args_to_buffer(int argc, char **argv, char *buffer);
char	*allocate_buffer(int argc, char **argv);
char	**args(char *str);

#endif