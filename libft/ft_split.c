/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 18:02:25 by mlaraki           #+#    #+#             */
/*   Updated: 2020/01/14 16:28:00 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_words_count(char const *s, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			j = 1;
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i])
				count++;
		}
		else
			i++;
	}
	return (count + j);
}

void	*free_result(char **result, int index)
{
	while (index)
		free(result[index--]);
	free(result);
	return (NULL);
}

char	*ft_assign_word(char const *s, char c, int i)
{
	int		size;
	int		j;
	char	*word;

	size = i;
	j = 0;
	while (s[size] != '\0' && s[size] != c)
		size++;
	if (!(word = (char *)malloc(((size - i) + 1) * sizeof(char))))
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		word[j] = s[i];
		i++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		words;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	words = ft_words_count(s, c);
	if (!(tab = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (i < words)
	{
		while (s[j] == c)
			j++;
		if (!(tab[i] = ft_assign_word(s, c, j)))
			return (free_result(tab, i));
		j += ft_strlen(tab[i]);
		i++;
	}
	tab[i] = (NULL);
	return (tab);
}
