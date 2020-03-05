/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:49:27 by mlaraki           #+#    #+#             */
/*   Updated: 2020/01/13 12:48:04 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*dest;
	const char	*s;

	dest = dst;
	s = src;
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
		*dest++ = *s++;
	return (dst);
}
