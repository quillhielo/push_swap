/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:19:24 by acarbajo          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:26 by acarbajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/// @brief copy memory area
/// @param dest memory destination
/// @param src memory source
/// @param n n bytes to copy
/// @return pointer to dest memory
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (n == 0 || (!src && !dest))
		return (dest);
	d = dest;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}
