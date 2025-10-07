/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:46 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/07 18:46:56 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	// FUNCION DE LIMPIEZA
	exit(EXIT_FAILURE);
}

t_node	*node_init(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node *));
	if (!new)
		error("Allocating failure\n");
	new->value = value;
	new->next = NULL;
	return (new);
}

void	place_node_a(t_framework *fw, t_node *new)
{
	if (fw->stack_a == NULL)
	{
		fw->stack_a = new;
	}
	else
	{
		new->next = fw->stack_a;
		fw->stack_a = new;
	}
}

void	place_node_b(t_framework *fw, t_node *new)
{
	if (fw->stack_b == NULL)
	{
		fw->stack_b = new;
	}
	else
	{
		new->next = fw->stack_b;
		fw->stack_b = new;
	}
}

int	matrix_len(char **split)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (split[i])
	{
		i++;
		len++;
	}
	return (len);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
