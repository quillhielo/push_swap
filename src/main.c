/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:03:35 by acarbajo          #+#    #+#             */
/*   Updated: 2025/10/22 21:28:59 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sucess_exit(t_framework *fw)
{
	clean_framework(fw);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)

{
	int			i;
	t_framework	*fw;

	if (argc < 2)
		return (0);
	fw = ft_calloc(1, sizeof(t_framework));
	if (!fw)
		ft_putstr_fd("Allocating failure", 2);
	i = argc - 1;
	while (i > 0)
	{
		parser(argv[i], fw);
		i--;
	}
	if (fw->amount <= 1)
		return (0);
	if (is_sorted(fw))
		sucess_exit(fw);
	if (fw->amount <= 5)
		sort_small(fw);
	radix_sort_chunk(fw);
	clean_framework(fw);
	return (0);
}
