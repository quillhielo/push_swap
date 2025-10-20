/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/16 20:33:08 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_framework *fw)
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
	write(1, "ra\n", 3);
	fw->moves++;
}

void	rb(t_framework *fw)
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
	write(1, "rb\n", 3);
	fw->moves++;
}

void	rr(t_framework *fw)
{
	ra_no_print(fw);
	rb_no_print(fw);
	write(1, "rr\n", 3);
	fw->moves++;
}

void	ra_no_print(t_framework *fw)
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
	fw->moves++;
}

void	rb_no_print(t_framework *fw)
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
	fw->moves++;
}
