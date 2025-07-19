/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 21:36:39 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 18:32:07 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		i;
	t_stack	*stack_a;
	t_stack	*current;

	i = 0;
	if (argc == 1)
		return (ft_printf("%s\n", "Error"), 0);
	if (argc == 2)
	{
		str = argv[1];
		stack_a = create_stack(str);
		if (!stack_a)
			return (ft_printf("%s\n", "Error"), 1);
	}
	else
	{
		str = allocate_buffer(argc, argv);
		copy_args_to_buffer(argc, argv, str);
		stack_a = create_stack(str);
		if (!stack_a)
			return (ft_printf("%s\n", "Error"), 1);
		free(str);
	}
	current = stack_a;
	while (current != NULL)
	{
		ft_printf("%d\n", current->number);
		current = current->next;
	}
	ft_stcclear(&stack_a);
	return (0);
}
