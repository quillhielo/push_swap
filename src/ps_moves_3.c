/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 17:41:21 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_framework *fw)
{
	t_node	*bottom;
	t_node	*temp;

	if (!fw->stack_a || !fw->stack_a->next)
		return ;
	temp = fw->stack_a;
	while (temp->next && temp->next->next)
		temp = temp->next;
	bottom = temp->next;
	temp->next = NULL;
	bottom->next = fw->stack_a;
	fw->stack_a = bottom;
	write(1, "rra\n", 4);
	fw->moves++;
}

void	rrb(t_framework *fw)
{
	t_node	*bottom;
	t_node	*temp;

	if (!fw->stack_b || !fw->stack_b->next)
		return ;
	temp = fw->stack_b;
	while (temp->next && temp->next->next)
		temp = temp->next;
	bottom = temp->next;
	temp->next = NULL;
	bottom->next = fw->stack_b;
	fw->stack_b = bottom;
	write(1, "rrb\n", 4);
	fw->moves++;
}

void	rra_no_print(t_framework *fw)
{
	t_node	*bottom;
	t_node	*temp;

	if (!fw->stack_a || !fw->stack_a->next)
		return ;
	temp = fw->stack_a;
	while (temp->next && temp->next->next)
		temp = temp->next;
	bottom = temp->next;
	temp->next = NULL;
	bottom->next = fw->stack_a;
	fw->stack_a = bottom;
}

void	rrb_no_print(t_framework *fw)
{
	t_node	*bottom;
	t_node	*temp;

	if (!fw->stack_b || !fw->stack_b->next)
		return ;
	temp = fw->stack_b;
	while (temp->next && temp->next->next)
		temp = temp->next;
	bottom = temp->next;
	temp->next = NULL;
	bottom->next = fw->stack_b;
	fw->stack_b = bottom;
}

void	rrr(t_framework *fw)
{
	rra_no_print(fw);
	rrb_no_print(fw);
	write(1, "rrr\n", 4);
	fw->moves++;
}
