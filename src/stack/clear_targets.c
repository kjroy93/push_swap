/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:35:25 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/26 19:38:51 by kmarrero         ###   ########.fr       */
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
