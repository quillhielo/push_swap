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
	if (fw->amount > 300)
		return (60);
	else if (fw->amount > 100)
		return (45);
	else
		return (15);
}

int	stack_size(t_node *stack)
{
	int	size;
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
				break;
		}

		if (pos <= stack_size(fw->stack_a) / 2)
			while (pos-- > 0)
				ra(fw);
		else
		{
			pos = stack_size(fw->stack_a) - pos;
			while (pos-- > 0)
				rra(fw);
		}

		pb(fw);

		// Repasar esta condicion
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
			break;

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
