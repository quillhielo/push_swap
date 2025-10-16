/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:46 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/13 12:12:04 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	// FUNCION DE LIMPIEZA
	exit(EXIT_FAILURE);
}

void	push_min_to_b(t_framework *fw, int min, int pos_min)
{
	while (fw->stack_a->value != min)
	{
		if (pos_min > fw->amount / 2)
			rra(fw);
		else
			ra(fw);
	}
	pb(fw);
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
