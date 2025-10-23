/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:41:39 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 20:01:00 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shorter_rotate(int pos, t_node *stack, t_framework *fw)
{
	if (pos <= stack_size(stack) / 2)
		while (pos-- > 0)
			ra(fw);
	else
	{
		pos = stack_size(stack) - pos;
		while (pos-- > 0)
			rra(fw);
	}
}

void	push_chunks_to_b(t_framework *fw)
{
	int	start;
	int	end;
	int	pos;
	int	chunk_size;

	assign_index(fw);
	chunk_size = get_chunk_size(fw);
	start = 0;
	end = chunk_size - 1;
	while (fw->stack_a)
	{
		pos = get_first_pos_in_chunk(fw->stack_a, start, end);
		if (pos == -1)
		{
			start += chunk_size;
			end += chunk_size;
			pos = get_first_pos_in_chunk(fw->stack_a, start, end);
			if (pos == -1)
				break ;
		}
		shorter_rotate(pos, fw->stack_a, fw);
		pb(fw);
		if (fw->stack_b && fw->stack_b->index < start + (chunk_size / 2))
			rb(fw);
	}
}

void	stack_a_recover(t_framework *fw)
{
	t_node	*temp;
	int		pos;
	int		index;

	index = fw->amount - 1;
	while (fw->stack_b)
	{
		temp = fw->stack_b;
		pos = 0;
		while (temp && temp->index != index)
		{
			temp = temp->next;
			pos++;
		}
		if (!temp)
			break ;
		if (pos <= stack_size(fw->stack_b) / 2)
			while (fw->stack_b->index != index)
				rb(fw);
		else
			while (fw->stack_b->index != index)
				rrb(fw);
		pa(fw);
		index--;
	}
}

void	radix_sort_chunk(t_framework *fw)
{
	push_chunks_to_b(fw);
	stack_a_recover(fw);
}
