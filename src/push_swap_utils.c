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

void	is_number(char *str) 
{
	int	i;
	i = 1;
	
	printf("%s", str);
	if (str[i]== '-'|| str[i] == '+')
	{
		if (!str[i + 1])
			error("Incorrect use of signs");
		i++;
	}
	printf("%s", str);
	while(str[i])
	{
		printf("%c", str[i]);
		if (!ft_isdigit(str[i]))
			error("Non-digit characters");
		i++;
	}
}
void	limits(int i)
{
	if (i < INT_MIN || i > INT_MAX)
		error("Surpassed limits");
}
int	parser(char *str, t_framework *fw)
{
	int	i;
	char	**split;
	int	number;
	
	if (str[0] == '\0')
		error("Empty argv");
	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
	{
		is_number(split[i]);
		number = ft_atoi(split[i]);
		limits(number);
		node_init(number);
		i++;
	}
	
	fw->amount++;
	return (0);
}

void	error(char *str)
{
	ft_putstr_fd("Error \n", 2);
	ft_putstr_fd(str, 2);
	//FUNCION DE LIMPIEZA
	exit(EXIT_FAILURE);
}