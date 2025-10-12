/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:12 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/09 17:42:06 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    assign_index(t_framework *fw)
{
    int i;
    t_node *temp;
    t_node *min;

    i = 0;
    while (i < fw->amount)
    {
        temp = fw->stack_a;
        min = NULL;
        while(temp)
	    {
		    if (temp->index == -1 && (!min || min->value > temp->value))
		    	min = temp;
		    temp = temp->next;
        }
        if(min)
            min->index = i;
        i++;
    }

}

int    get_max_bits(t_framework *fw)
{
    int max_num;
    int max_bits;

    max_num = fw->amount - 1;
    max_bits = 0;
    while((max_num >> max_bits) != 0)
        max_bits++;
    return (max_bits);
}

void radix_sort(t_framework *fw)
{
    int max_bits;
    int i;
    int l;

    assign_index(fw);
    max_bits = get_max_bits(fw);

    i = 0;
    while (i < max_bits)
    {
        l = 0;
        while (l < fw->amount)
        {
            if (((fw->stack_a->index >> i) & 1) == 1)
                ra(fw);
            else
                pb(fw);
            l++;
        }
        while (fw->stack_b)
            pa(fw);
        i++;
    }
}
