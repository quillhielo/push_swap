/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:21 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 22:15:19 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dupe_check(int number, t_framework *fw, char **split)
{
	t_node	*temp;
	t_node	*next;

	temp = fw->stack_a;
	while (temp)
	{
		if (temp->value == number)
		{
			free_matrix(split);
			error(fw);
		}
		next = temp->next;
		temp = next;
	}
}

int	atoi_result_checker(long r, long s, t_framework *fw, char **split)
{
	if (r * s < INT_MIN || r * s > INT_MAX)
	{
		free_matrix(split);
		error(fw);
	}
	return ((int)(r * s));
}

int	ft_atoi_limits(const char *nptr, t_framework *fw, char **split)
{
	size_t		i;
	long		s;
	long		r;
	long		d;

	i = 0;
	s = 1;
	r = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			s = s * -1;
		i++;
	}
	if (!(nptr[i] >= 48 && nptr[i] <= 57))
		return (0);
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		d = nptr[i] - 48;
		r = r * 10 + d;
		i++;
	}
	return (atoi_result_checker(r, s, fw, split));
}

void	is_number(char *str, t_framework *fw, char **split)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1] || str[i + 1] == '-' || str[i + 1] == '+')
			error(fw);
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			free_matrix(split);
			error(fw);
		}
		i++;
	}
}

int	parser(char *str, t_framework *fw)
{
	int		i;
	char	**split;
	int		number;
	t_node	*new;

	if (str[0] == '\0')
		error(fw);
	if (is_space(str))
		error(fw);
	split = ft_split(str, ' ');
	i = matrix_len(split) - 1;
	while (i >= 0)
	{
		is_number(split[i], fw, split);
		number = ft_atoi_limits(split[i], fw, split);
		dupe_check(number, fw, split);
		new = node_init(number, fw);
		place_node_a(fw, new);
		fw->amount++;
		i--;
	}
	free_matrix(split);
	return (0);
}
