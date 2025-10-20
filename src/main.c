/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:35 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/16 20:41:07 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *s_a)
{
	t_node	*num;
	t_node	*temp;

	num = s_a;
	while (num)
	{
		printf("%i --- %i\n", num->value, num->index);
		temp = num->next;
		num = temp;
	}
}

int	main(int argc, char **argv)

{
	int			i;
	t_framework	*fw;

	if (argc < 2)
		return (0);
	fw = ft_calloc(1, sizeof(t_framework));
	if (!fw)
		error("Allocating failure");
	i = argc - 1;
	while (i > 0)
	{
		parser(argv[i], fw);
		i--;
	}
	if (fw->amount <= 1)
		return (0);
	if (fw->amount <= 5)
		sort_small(fw);
	radix_sort_chunk(fw);
	printf("----------------------------------------------------\n");
	print_stack(fw->stack_a);
	printf("%i\n", fw->moves);
	return (0);
}
