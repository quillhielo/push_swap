/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/07 18:47:47 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_framework *fw)
{
	t_node	*top;
	t_node	*temp;

	if (!fw->stack_a || !fw->stack_a->next)
		return ;
	top = fw->stack_a;
	temp = fw->stack_a;
	fw->stack_a = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
}

void	rotate_b(t_framework *fw)
{
	t_node	*top;
	t_node	*temp;

	if (!fw->stack_b || !fw->stack_b->next)
		return ;
	top = fw->stack_b;
	temp = fw->stack_b;
	fw->stack_b = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = top;
	top->next = NULL;
}

void	rotate_rr(t_framework *fw)
{
	rotate_a(fw);
	rotate_b(fw);
}
