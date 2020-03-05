/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:37:09 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:22:51 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_c(va_list *ap, t_flags **obj)
{
	char c;

	c = (char)va_arg(*ap, int);
	if ((*obj)->width && !(*obj)->minus)
	{
		(*obj)->zero == 1 ? ft_putchar_zero((*obj)->width - 1) :
			ft_putchar_space((*obj)->width - 1);
		(*obj)->result_length += (*obj)->width - 1;
	}
	ft_putchar_fd(c, 1);
	if ((*obj)->width && (*obj)->minus)
	{
		ft_putchar_space((*obj)->width - 1);
		(*obj)->result_length += (*obj)->width - 1;
	}
	(*obj)->result_length++;
}
