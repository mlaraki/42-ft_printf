/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:55:55 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:39:16 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_handle_length(t_flags **obj, int length,
		unsigned long long pointer, char *str)
{
	ft_putstr_fd("0x", 1);
	(*obj)->result_length += 2;
	if ((*obj)->precision > 0 && (*obj)->dot == 1)
	{
		ft_putchar_zero((*obj)->precision - length);
		if ((*obj)->precision - length > 0)
			(*obj)->result_length += (*obj)->precision - length;
	}
	if (!((*obj)->precision == 0 && (*obj)->dot == 1 && pointer == 0))
	{
		ft_putstr_fd(str, 1);
		(*obj)->result_length += length;
	}
}

void	ft_compute_p(t_flags **obj, unsigned long long pointer, int length,
		char *str)
{
	int	nprinted;
	int iszero;

	iszero = pointer == 0 ? 1 : 0;
	nprinted = length > 0 ? 2 : 0;
	if (iszero && !((*obj)->precision == 0 && (*obj)->dot == 1 && pointer == 0))
		nprinted += 1;
	if (((*obj)->width - ((nprinted + length) - iszero) > 0) && !(*obj)->minus)
	{
		ft_putchar_space((*obj)->width - ((nprinted + length) - iszero));
		(*obj)->result_length += (*obj)->width - ((nprinted + length) - iszero);
	}
	if (length)
	{
		ft_handle_length(obj, length, pointer, str);
		free(str);
	}
	if (((*obj)->width - ((nprinted + length) - iszero) > 0 && (*obj)->minus))
	{
		ft_putchar_space((*obj)->width - ((nprinted + length) - iszero));
		(*obj)->result_length += (*obj)->width - ((nprinted + length) - iszero);
	}
}

void	ft_handle_p(va_list *ap, t_flags **obj)
{
	unsigned long long	pointer;
	char				*str;
	int					length;
	int					iszero;

	pointer = (unsigned long long)va_arg(*ap, void *);
	if (!(str = ft_itoa_base(pointer, 16, 0)))
		return ;
	length = (int)ft_strlen(str);
	if ((*obj)->dot && (*obj)->precision == 0)
		length = 0;
	iszero = pointer == 0 ? 1 : 0;
	length = (int)ft_strlen(str);
	ft_compute_p(obj, pointer, length, str);
}
