/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:41:34 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:11 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_struct(t_flags **obj)
{
	(*obj)->precision = 0;
	(*obj)->width = 0;
	(*obj)->minus = 0;
	(*obj)->zero = 0;
	(*obj)->dot = 0;
	(*obj)->space = 0;
	(*obj)->star = 0;
	(*obj)->init_mod = 0;
	(*obj)->result_length = 0;
	(*obj)->precision_minus = 0;
}

void	ft_clear(va_list *ap, t_flags **obj)
{
	if ((*obj)->init_mod == 1)
		free((*obj)->modifiers);
	free(*obj);
	va_end(*ap);
}

void	ft_reset_modifiers(t_flags **obj)
{
	if ((*obj)->init_mod == 1)
	{
		free((*obj)->modifiers);
		(*obj)->init_mod = 0;
	}
	(*obj)->precision = 0;
	(*obj)->width = 0;
	(*obj)->minus = 0;
	(*obj)->zero = 0;
	(*obj)->dot = 0;
	(*obj)->space = 0;
	(*obj)->star = 0;
	(*obj)->precision_minus = 0;
}
