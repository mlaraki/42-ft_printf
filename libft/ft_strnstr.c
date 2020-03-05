/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:21:14 by mlaraki           #+#    #+#             */
/*   Updated: 2020/01/10 18:25:06 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[count] != '\0' && count < (int)len)
	{
		while (haystack[count + count2] == needle[count2] &&
			haystack[count + count2] != '\0' && (count + count2) < (int)len)
			count2++;
		if (needle[count2] == '\0')
			return ((char*)(haystack + count));
		count++;
		count2 = 0;
	}
	return (NULL);
}
