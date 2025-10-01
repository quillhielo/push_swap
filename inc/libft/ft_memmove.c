/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:19:24 by acarbajo          #+#    #+#             */
/*   Updated: 2025/04/24 21:16:15 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief copy n bytes from src to dest memmory
/// @param dest memmory area where we copy src
/// @param src the source from where we copy
/// @param n number of bytes that we copy
/// @return pointer to dest

static void	upper_move(unsigned char *d, const unsigned char *s, size_t n)
{
	size_t					i;

	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = dest;
	s = src;
	if (n == 0 || (!dest && !src))
		return (dest);
	if (d < s || d >= s + n)
		upper_move(d, s, n);
	else
	{
		i = n -1;
		while (i > 0)
		{
			d[i] = s[i];
			i--;
		}
		d[i] = s[i];
	}
	return (dest);
}
