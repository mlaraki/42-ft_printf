/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:34:41 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:22:59 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_handle_d_left2(t_flags **obj, int len, int isnegative, int minus)
{
	if (!(*obj)->minus)
	{
		if ((*obj)->zero == 1 && (*obj)->dot == 0)
		{
			minus = ft_handle_d_minus(isnegative, minus);
			(*obj)->result_length += ft_putchar_zero((*obj)->width - len);
		}
		else if ((*obj)->dot)
		{
			if ((*obj)->precision < len)
				(*obj)->result_length +=
					ft_putchar_space((*obj)->width - len);
			else if ((*obj)->width - (*obj)->precision - isnegative > 0)
				(*obj)->result_length +=
					ft_putchar_space((*obj)->width - (*obj)->precision -
							isnegative);
		}
		else if (!(*obj)->dot && (*obj)->width - len > 0)
			(*obj)->result_length += ft_putchar_space((*obj)->width - len);
	}
	minus = ft_handle_d_minus(isnegative, minus);
	return (minus);
}
