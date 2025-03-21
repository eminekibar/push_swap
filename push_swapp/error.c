/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:47:54 by ekibar            #+#    #+#             */
/*   Updated: 2025/03/18 14:55:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_numeric(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_duplicate(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_valid_int(char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

void	control2(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (!(argv[i][j + 1] <= '9' && argv[i][j
					+ 1] >= '0'))
				{
					write(2, "Error\n", 6);
					free_argv(argv);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

void	error_control(int argc, char **argv)
{
	control2(argv);
	if (!ft_is_numeric(argv))
	{
		write(2, "Error\n", 6);
		free_argv(argv);
		exit(1);
	}
	if (!is_valid_int(argv))
	{
		write(2, "Error\n", 6);
		free_argv(argv);
		exit(1);
	}
	if (is_duplicate(argv, argc))
	{
		write(2, "Error\n", 6);
		free_argv(argv);
		exit(1);
	}
}
