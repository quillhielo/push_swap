/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/16 20:57:59 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_framework *fw)
{
	int		i;
	t_node	*temp;
	t_node	*min;

	i = 0;
	while (i < fw->amount)
	{
		temp = fw->stack_a;
		min = NULL;
		while (temp)
		{
			if (temp->index == -1 && (!min || min->value > temp->value))
				min = temp;
			temp = temp->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}

int	get_chunk_size(t_framework *fw)
{
	int	i;
	if(fw->amount > 300)
		i = 60;
	else if(fw->amount > 100)
		i = 45;
	else
		i = 15;
	return (i);
}
void	stack_a_recover(t_framework *fw)
{
	t_node	*temp;
	int 	pos;
	int		index;

	index = fw->amount - 1;
	while(fw->stack_b)
	{
		temp = fw->stack_b;
		pos = 0;
		while (temp)
		{
			if (temp->index == index)
				break;
			temp = temp->next;
			pos++;	
		}
		while (fw->stack_b->index != index)
		{
			if(pos > index/2)
				rrb(fw);
			else
				rb(fw);
		}
		pa(fw);
		index--;		
	}
}


void	radix_sort_chunk(t_framework *fw)
{
	int	start;
	int	end;
	int	chunk_l;
	int	pushed;

	assign_index(fw);
	chunk_l = get_chunk_size(fw);
	pushed = 0;
	start = 0;
	end = chunk_l - 1;
	while (fw->stack_a)
	{
		if (fw->stack_a->index >= start &&	fw->stack_a->index <= end)
		{
			pb(fw);
			pushed++;
			if ((end / 2) > fw->stack_b->index)
				rb (fw);
		}
		else
			ra(fw);
		if (pushed >= chunk_l)
		{
			start += chunk_l;
			end += chunk_l;
		}
	}
	stack_a_recover(fw);
}
