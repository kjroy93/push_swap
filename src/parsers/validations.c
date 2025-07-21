/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjroy93 <kjroy93@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 14:12:43 by kmarrero          #+#    #+#             */
/*   Updated: 2025/07/21 21:42:10 by kjroy93          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	is_valid_range(char *str, int sign)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (sign == 1 && (result > (INT_MAX - (str[i] - '0')) / 10))
			return (0);
		if (sign == -1 && (result > ((long)INT_MAX + 1 - (str[i] - '0')) / 10))
			return (0);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

static int	is_valid_integer_format(char *str)
{
	int	sign;
	int	i;

	sign = 1;
	if (!str || *str == '\0')
		return (0);
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
		if (str[i] == '\0')
			return (0);
	}
	if (!is_valid_range(str + i, sign))
		return (0);
	return (1);
}

int	main_validation(char **argv)
{
	int	num1;
	int	num2;
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		if (!is_valid_integer_format(argv[i]))
			return (0);
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (!is_valid_integer_format(argv[j]))
				return (0);
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
