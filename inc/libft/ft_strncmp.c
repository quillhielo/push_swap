/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:31:43 by acarbajo          #+#    #+#             */
/*   Updated: 2025/04/24 19:24:34 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief compares strings s1 and s2 until n bytes
/// @param s1 string1
/// @param s2 string2
/// @param n max number bytes to compare
/// @return int with the diference
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
		i++;
	}
	if (i < n)
		return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
	return (0);
}
