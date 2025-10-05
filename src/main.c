/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 14:52:37 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/01 16:50:23 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_node *s_a)
{
	t_node *num;
	t_node	*temp;
	num = s_a;
	while (num)
	{
		printf("%i\n", num->value);
		temp = num->next;
		num = temp;
	}

}

int	main(int argc, char **argv)

{
	int i;
	t_framework *fw;
	
	if (argc < 2)
		return (0);
	fw = ft_calloc(1, sizeof(t_framework *));
	if (!fw)
		error("Allocating failure");
	i = argc - 1;
	while(i > 0)
	{
		parser(argv[i], fw);
		i--;
	}
	print_stack(fw->stack_a);
	printf("Número de dígitos: %i\n", fw->amount);
	swap_a(fw);
	print_stack(fw->stack_a);
	push_b(fw);
	printf("----------\n");
	print_stack(fw->stack_a);
	printf("----------\n");
	print_stack(fw->stack_b);
	push_a(fw);
	printf("----------\n");
	print_stack(fw->stack_a);
	printf("----------\n");
	print_stack(fw->stack_b);
	return (0);
}

