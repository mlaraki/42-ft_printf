/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:36:03 by mlaraki           #+#    #+#             */
/*   Updated: 2020/01/13 12:36:08 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *list;
	t_list *nextlist;

	if (!lst || !(list = *lst) || !del)
		return ;
	while (list)
	{
		nextlist = list->next;
		del(list->content);
		free(list);
		list = nextlist;
	}
	*lst = (NULL);
}
