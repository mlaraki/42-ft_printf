/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers_handler2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:45:33 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:14 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_modifiers(t_flags **obj)
{
	if ((*obj)->init_mod == 0)
	{
		(*obj)->modifiers = (char *)malloc(sizeof(char) + 1);
		(*obj)->modifiers[0] = '%';
		(*obj)->modifiers[1] = '\0';
		(*obj)->init_mod = 1;
	}
}
