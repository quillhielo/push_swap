/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:21 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/13 12:16:38 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dupe_check(int number, t_framework *fw)
{
	t_node	*temp;
	t_node	*next;

	temp = fw->stack_a;
	while (temp)
	{
		if (temp->value == number)
			error("Dup numbers\n");
		next = temp->next;
		temp = next;
	}
}

int	ft_atoi_limits(const char *nptr)
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
		if ((r * 10 + d) * s < INT_MIN || (r * 10 + d) * s > INT_MAX)
			error("Surpassed INT limits\n");
		r = r * 10 + d;
		i++;
	}
	return ((int)(r * s));
}

void	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!str[i + 1] || str[i + 1] == '-' || str[i + 1] == '+')
			error("Incorrect use of signs\n");
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error("Non-digit characters\n");
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
		error("Empty argv");
	split = ft_split(str, ' ');
	i = matrix_len(split) - 1;
	while (i >= 0)
	{
		is_number(split[i]);
		number = ft_atoi_limits(split[i]);
		dupe_check(number, fw);
		new = node_init(number);
		place_node_a(fw, new);
		fw->amount++;
		i--;
	}
	free_matrix(split);
	return (0);
}
