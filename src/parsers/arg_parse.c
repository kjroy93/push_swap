/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:14:40 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/19 18:39:22 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

char	**args(char *str)
{
	char	**args;

	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	if (!args)
		return (NULL);
	return (args);
}

char	*allocate_buffer(int argc, char **argv)
{
	char	*buffer;
	int		size;
	int		i;

	i = 1;
	size = 0;
	while (i < argc)
	{
		size += ft_strlen(argv[i]);
		i++;
	}
	if (argc > 2)
		size += (argc - 2);
	buffer = malloc(size + 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}

void	copy_args_to_buffer(int argc, char **argv, char *buffer)
{
	int	pos;
	int	len;
	int	i;
	int	j;

	pos = 0;
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		j = 0;
		while (j < len)
		{
			buffer[pos] = argv[i][j];
			pos++;
			j++;
		}
		if (i < argc - 1)
		{
			buffer[pos] = ' ';
			pos++;
		}
		i++;
	}
	buffer[pos] = '\0';
}
