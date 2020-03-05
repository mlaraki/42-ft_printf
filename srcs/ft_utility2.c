/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:55:08 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:21 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_itoa_base(unsigned long long value, unsigned long long base,
		int maj)
{
	char				*s;
	unsigned long long	n;
	int					i;
	char				el;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	el = maj ? 'A' : 'a';
	while (i-- > 0)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + el - 10;
		n /= base;
	}
	return (s);
}

char	*ft_strnew(size_t size)
{
	char *start;

	start = (char *)malloc((size + 1) * sizeof(*start));
	if (!start)
		return (NULL);
	ft_bzero(start, size + 1);
	return (start);
}
