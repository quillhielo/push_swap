/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:31:26 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/09 19:30:44 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_framework *fw)
{
	int a;
	int b;
	int c;

	a = fw->stack_a->value;
	b = fw->stack_a->next->value;
	c = fw->stack_a->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < b && b > c && c > a)
	{
		rra(fw);
		sa(fw);
	}
	else if (a > b && b < c && c > a)
		sa(fw);
	else if (a < b && b > c && c < a)
		rra(fw);
	else if (a > b && b < c && c < a)
		ra(fw);
	else if (a > b && b > c && c < a)
	{
		ra(fw);
		sa(fw);	
	}
}

void sort_two(t_framework *fw)
{
    if (fw->stack_a->value > fw->stack_a->next->value)
        sa(fw);
}
void	push_min_to_b(t_framework *fw, int min, int pos_min)
{
	while (fw->stack_a->value != min)
	{
		if (pos_min > fw->amount/2)
			rra(fw);
		else
			ra(fw);
	}
	pb(fw);
}
void	sort_four(t_framework *fw)
{
	int	min;
	int	pos;
	int pos_min;
	t_node	*temp;
	
	min = fw->stack_a->value;
	temp = fw->stack_a->next;
	pos = 2;
	pos_min = 1;
	while(temp)
	{
		if (min > temp->value)
		{
			min = temp->value;
			pos_min = pos;
		}
		temp = temp->next;
		pos++;		
	}
	push_min_to_b(fw, min, pos_min);
	sort_three(fw);
	pa(fw);
}


void	sort_five(t_framework *fw)
{
	int	min;
	int	pos;
	int pos_min;
	t_node	*temp;
	
	min = fw->stack_a->value;
	temp = fw->stack_a->next;
	pos = 2;
	pos_min = 1;
	while(temp)
	{
		if (min > temp->value)
		{
			min = temp->value;
			pos_min = pos;
		}
		temp = temp->next;
		pos++;		
	}
	push_min_to_b(fw, min, pos_min);
	sort_four(fw);
	pa(fw);	
}
void	sort_small(t_framework *fw)
{
	if (fw->amount == 2)
		sort_two(fw);
	if (fw->amount == 3)
		sort_three(fw);
	if (fw->amount == 4)
		sort_four(fw);
	if (fw->amount == 5)
		sort_five(fw);
}