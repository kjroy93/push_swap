/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:59:04 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 14:06:48 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	free_split(char **args)
{
	int	index;

	index = 0;
	if (!args)
		return ;
	while (args[index])
	{
		free(args[index]);
		args[index] = NULL;
		index++;
	}
	free(args);
}
