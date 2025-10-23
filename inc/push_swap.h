/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:00 by alba              #+#    #+#             */
/*   Updated: 2025/10/22 21:20:04 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_framework
{
	t_node			*stack_a;
	t_node			*stack_b;
	int				amount;
	int				moves;
}					t_framework;

void				free_stack(t_node *stack);
void				clean_framework(t_framework *fw);
void				error(t_framework *fw);
int					is_space(char *str);
t_node				*node_init(int value, t_framework *fw);
void				place_node_a(t_framework *fw, t_node *new);
void				place_node_b(t_framework *fw, t_node *new);
int					matrix_len(char **split);
void				free_matrix(char **matrix);
void				dupe_check(int number, t_framework *fw);
int					atoi_result_checker(long r, long s, t_framework *fw);
int					ft_atoi_limits(const char *nptr, t_framework *fw);
void				is_number(char *str, t_framework *fw);
int					parser(char *str, t_framework *fw);
void				sa(t_framework *fw);
void				sa_no_print(t_framework *fw);
void				sb(t_framework *fw);
void				sb_no_print(t_framework *fw);
void				ss(t_framework *fw);
void				pa(t_framework *fw);
void				pb(t_framework *fw);
void				ra(t_framework *fw);
void				rb(t_framework *fw);
void				rr(t_framework *fw);
void				ra_no_print(t_framework *fw);
void				rb_no_print(t_framework *fw);
void				rra(t_framework *fw);
void				rrb(t_framework *fw);
void				rra_no_print(t_framework *fw);
void				rrb_no_print(t_framework *fw);
void				rrr(t_framework *fw);
void				push_min_to_b(t_framework *fw, int min, int pos_min);
int					is_sorted(t_framework *fw);
void				sort_two(t_framework *fw);
void				sort_three(t_framework *fw);
void				sort_four(t_framework *fw);
void				sort_five(t_framework *fw);
void				sort_small(t_framework *fw);
void				assign_index(t_framework *fw);
int					get_chunk_size(t_framework *fw);
void				stack_a_recover(t_framework *fw);
int					stack_size(t_node *stack);
int					get_first_pos_in_chunk(t_node *stack, int start, int end);
void				shorter_rotate(int pos, t_node *stack, t_framework *fw);
void				push_chunks_to_b(t_framework *fw);
void				radix_sort_chunk(t_framework *fw);

#endif
