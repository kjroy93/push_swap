/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:24:21 by kjroy93           #+#    #+#             */
/*   Updated: 2025/07/25 19:48:19 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_targets(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		current->target = NULL;
		current = current->next;
	}
}
