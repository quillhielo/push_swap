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

t_node	*node_init(int value)
{
	t_node	*new;
	new = (t_node *)malloc(sizeof(t_node *));
	if (!new)
		error("Allocating failure");
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
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
	
	i = 0;
	while(i < argc)
	{
		parser(argv[i], fw);
		i++;
	}
	return (0);
}
