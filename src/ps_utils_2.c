/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:46 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 21:30:09 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_framework *fw)
{
	ft_putstr_fd("Error\n", 2);
	clean_framework(fw);
	exit(EXIT_FAILURE);
}

int	is_sorted(t_framework *fw)
{
	t_node	*temp;

	temp = fw->stack_a;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	free_stack(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (stack)
	{
		stack = stack->next;
		free(temp);
		temp = stack;
	}
}

void	clean_framework(t_framework *fw)
{
	if (!fw)
		return ;
	if (fw->stack_a)
		free_stack(fw->stack_a);
	if (fw->stack_b)
		free_stack(fw->stack_b);
	free(fw);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
