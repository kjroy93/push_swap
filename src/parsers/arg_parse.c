/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarrero <kmarrero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 17:14:40 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/26 18:38:42 by kmarrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static char	**args(char *str)
{
	char	**args;

	if (!str)
		return (NULL);
	args = ft_split(str, ' ');
	if (!args)
		return (NULL);
	return (args);
}

static char	*allocate_buffer(int argc, char **argv)
{
	char	*buffer;
	int		size;
	int		i;

	size = 0;
	i = 1;
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

static void	copy_args_to_buffer(int argc, char **argv, char *buffer)
{
	int	pos;
	int	len;
	int	i;
	int	j;

	i = 1;
	pos = 0;
	while (i < argc)
	{
		j = 0;
		len = ft_strlen(argv[i]);
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

char	**parse_single_argument(char *arg)
{
	char	**arguments;

	arguments = args(arg);
	if (!arguments)
		return (NULL);
	if (!main_validation(arguments))
	{
		free_split(arguments);
		return (NULL);
	}
	return (arguments);
}

char	**parse_multiple_arguments(int argc, char **argv)
{
	char	*buffer;
	char	**arguments;

	buffer = allocate_buffer(argc, argv);
	if (!buffer)
		return (NULL);
	copy_args_to_buffer(argc, argv, buffer);
	arguments = args(buffer);
	free(buffer);
	if (!arguments)
		return (NULL);
	if (!main_validation(arguments))
	{
		free_split(arguments);
		return (NULL);
	}
	return (arguments);
}
