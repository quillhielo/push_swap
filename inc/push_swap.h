/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 17:31:00 by alba              #+#    #+#             */
/*   Updated: 2025/10/01 14:52:58 by acarbajo         ###   ########.fr       */
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
	struct s_node	*next;
}	t_node;

typedef struct s_framework 
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		amount;
}	t_framework;

void	error(char *str);
t_node	*node_init(int value);
void	place_node_a(t_framework *fw, t_node *new);
void	place_node_b(t_framework *fw, t_node *new);
int		matrix_len(char **split);
void	free_matrix(char **matrix);
void	dupe_check(int number, t_framework *fw);
void	limits(int i);
void	is_number(char *str);
int		parser(char *str, t_framework *fw);
void 	swap_a(t_framework *fw);
void 	swap_b(t_framework *fw);
void 	swap_ss(t_framework *fw);
void    push_a(t_framework *fw);
void    push_b(t_framework *fw);

#endif
