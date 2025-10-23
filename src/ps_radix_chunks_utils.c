/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_radix_chunks_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 17:41:39 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 20:15:39 by acarbajo         ###   ########.fr       */
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
	if (fw->amount >= 500)
		return (fw->amount / 10);
	else if (fw->amount >= 400)
		return (fw->amount / 9);
	else if (fw->amount >= 300)
		return (fw->amount / 8);
	else if (fw->amount >= 200)
		return (fw->amount / 7);
	else if (fw->amount >= 100)
		return (fw->amount / 5);
	else
		return (fw->amount / 5);
}

int	stack_size(t_node *stack)
{
	int		size;
	t_node	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

int	get_first_pos_in_chunk(t_node *stack, int start, int end)
{
	int		pos;
	t_node	*temp;

	pos = 0;
	temp = stack;
	while (temp)
	{
		if (temp->index >= start && temp->index <= end)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (-1);
}
