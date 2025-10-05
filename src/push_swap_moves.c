/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:20:04 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/01 15:53:35 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_framework *fw)
{
    t_node  *top;
    t_node  *bottom;

    if (fw->stack_a == 0 || fw->stack_a->next == 0)
        return;
    top = ft_calloc(1, sizeof(t_node *));
    if (!top)
        error("Allocating failure");
    bottom = ft_calloc(1, sizeof(t_node *));
    if (!bottom)
        error("Allocating failure");
    top->value = fw->stack_a->value;
    bottom->value = fw->stack_a->next->value;
    fw->stack_a->value = bottom->value;
    fw->stack_a->next->value = top->value;
    free(top);
    free(bottom);
    top = NULL;
    bottom = NULL;
}

void swap_b(t_framework *fw)
{
    t_node  *top;
    t_node  *bottom;

    if (fw->stack_b == 0 || fw->stack_b->next == 0)
        return;
    top = ft_calloc(1, sizeof(t_node *));
    if (!top)
        error("Allocating failure");
    bottom = ft_calloc(1, sizeof(t_node *));
    if (!bottom)
        error("Allocating failure");
    top->value = fw->stack_b->value;
    bottom->value = fw->stack_b->next->value;
    fw->stack_b->value = bottom->value;
    fw->stack_b->next->value = top->value;
    free(top);
    free(bottom);
    top = NULL;
    bottom = NULL;
}

void swap_ss(t_framework *fw)
{
    swap_a(fw);
    swap_b(fw);
}

void    push_a(t_framework *fw)
{
    t_node  *new_a;
    if (fw->stack_b == NULL)
        return ;
    new_a = ft_calloc(1, sizeof(t_node *));
    if (!new_a)
        error("Allocating failure");
    new_a->value = fw->stack_b->value;
    fw->stack_b = fw->stack_b->next;
    place_node_a(fw, new_a);
}

void    push_b(t_framework *fw)
{
    t_node  *new_b;
    if (fw->stack_a == NULL)
        return ;
    new_b = ft_calloc(1, sizeof(t_node *));
    if (!new_b)
        error("Allocating failure");
    new_b->value = fw->stack_a->value;
    fw->stack_a = fw->stack_a->next;
    place_node_b(fw, new_b);
}


