/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 21:23:13 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_framework *fw)
{
	t_node	*new_a;

	if (fw->stack_b == NULL)
		return ;
	new_a = fw->stack_b;
	fw->stack_b = fw->stack_b->next;
	new_a->next = NULL;
	place_node_a(fw, new_a);
	write(1, "pa\n", 3);
	fw->moves++;
}

void	pb(t_framework *fw)
{
	t_node	*new_b;

	new_b = fw->stack_a;
	fw->stack_a = fw->stack_a->next;
	new_b->next = NULL;
	place_node_b(fw, new_b);
	write(1, "pb\n", 3);
	fw->moves++;
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
