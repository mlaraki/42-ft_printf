/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:27:08 by mlaraki           #+#    #+#             */
/*   Updated: 2020/01/13 12:40:19 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init(size_t *i, size_t *start, size_t *end, char const *s1)
{
	*i = 0;
	*start = 0;
	*end = ft_strlen(s1) - 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (!s1 || ft_strlen(s1) == 0)
	{
		if (!(str = malloc(sizeof(char) * (1))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	ft_init(&i, &start, &end, s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && start <= end)
		end--;
	if (!(str = malloc(sizeof(char) * (start > end ? 1 : (end - start + 2)))))
		return (NULL);
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
