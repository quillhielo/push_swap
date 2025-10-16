/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:00 by alba              #+#    #+#             */
/*   Updated: 2025/10/16 20:31:20 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_framework 
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		amount;
	int		moves;
}	t_framework;

void	error(char *str);
t_node	*node_init(int value);
void	place_node_a(t_framework *fw, t_node *new);
void	place_node_b(t_framework *fw, t_node *new);
int		matrix_len(char **split);
void	free_matrix(char **matrix);
void	dupe_check(int number, t_framework *fw);
int	ft_atoi_limits (const char *nptr);
void	is_number(char *str);
int		parser(char *str, t_framework *fw);
void 	sa(t_framework *fw);
void 	sb(t_framework *fw);
void 	ss(t_framework *fw);
void    pa(t_framework *fw);
void    pb(t_framework *fw);
void 	ra(t_framework *fw);
void 	rb(t_framework *fw);
void    rr(t_framework *fw);
void	rra(t_framework *fw);
void	rrb(t_framework *fw);
void    rrr(t_framework *fw);
void	push_min_to_b(t_framework *fw, int min, int pos_min);
int		is_sorted(t_framework *fw);
void	sort_two(t_framework *fw);
void	sort_three(t_framework *fw);
void	sort_four(t_framework *fw);
void	sort_five(t_framework *fw);
void	sort_small(t_framework *fw);
void    assign_index(t_framework *fw);
void	stack_a_recover(t_framework *fw);
void	radix_sort_chunk(t_framework *fw);
int		get_chunk_size(t_framework *fw);

#endif
