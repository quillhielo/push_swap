/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/07 18:12:27 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_framework *fw)
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

void	reverse_rotate_b(t_framework *fw)
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

void	reverse_rotate_rrr(t_framework *fw)
{
	reverse_rotate_a(fw);
	reverse_rotate_b(fw);
}
