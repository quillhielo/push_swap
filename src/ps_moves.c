/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 17:40:48 by acarbajo         ###   ########.fr       */
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

void	sa_no_print(t_framework *fw)
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

void	sb_no_print(t_framework *fw)
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
}

void	ss(t_framework *fw)
{
	sa_no_print(fw);
	sb_no_print(fw);
	write(1, "ss\n", 3);
	fw->moves++;
}
