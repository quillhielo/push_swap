/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/16 20:32:52 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_framework *fw)
{
	t_node	*top;
	t_node	*bottom;

	if (!fw->stack_a || !fw->stack_a->next)
		return ;
	top = fw->stack_a;
	bottom = fw->stack_a->next;
	top->next = bottom->next;
	bottom->next = top;
	fw->stack_a = bottom;
	write(1, "sa\n", 3);
	fw->moves++;
}

void	sb(t_framework *fw)
{
	t_node	*top;
	t_node	*bottom;

	if (!fw->stack_b || !fw->stack_b->next)
		return ;
	top = fw->stack_b;
	bottom = fw->stack_b->next;
	top->next = bottom->next;
	bottom->next = top;
	fw->stack_b = bottom;
	write(1, "sb\n", 3);
	fw->moves++;
}

void	ss(t_framework *fw)
{
	sa(fw);
	sb(fw);
	write(1, "ss\n", 3);
	fw->moves++;
}

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
