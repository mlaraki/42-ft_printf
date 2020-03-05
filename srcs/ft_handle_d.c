/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:39:46 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/05 11:08:24 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_d_star(t_flags **obj)
{
	if ((*obj)->star && (*obj)->precision_minus)
		(*obj)->precision *= -1;
	if ((*obj)->star && (*obj)->width < 0)
		(*obj)->width *= -1;
}

int		ft_handle_d_minus(int isnegative, int printed)
{
	int minus;

	minus = 0;
	if (isnegative && !printed)
	{
		ft_putchar_fd('-', 1);
		minus = 1;
	}
	return (minus);
}

int		ft_handle_d_left(t_flags **obj, int len, int isnegative, int minus)
{
	if (((*obj)->width - len + isnegative) > 0)
	{
		minus = ft_handle_d_left2(obj, len, isnegative, minus);
	}
	else if (isnegative && !minus)
		minus = ft_handle_d_minus(isnegative, minus);
	return (minus);
}

void	ft_handle_d_right(t_flags **obj, int len, int isnegative, char **str)
{
	if ((*obj)->precision - len + isnegative > 0)
		(*obj)->result_length +=
		ft_putchar_zero((*obj)->precision - len + isnegative);
	ft_putstr_fd(*str, 1);
	(*obj)->result_length += len;
	if (((*obj)->width - len) > 0)
	{
		if ((*obj)->minus)
		{
			if ((*obj)->precision < len)
				(*obj)->result_length += ft_putchar_space((*obj)->width - len);
			else if ((*obj)->width - (*obj)->precision - isnegative > 0)
				(*obj)->result_length +=
					ft_putchar_space((*obj)->width -
					(*obj)->precision - isnegative);
		}
	}
}

void	ft_handle_d(va_list *ap, t_flags **obj)
{
	int		num;
	int		len;
	int		isnegative;
	char	*str;
	int		minus;

	minus = 0;
	num = (int)va_arg(*ap, int);
	if (num == 0 && (*obj)->dot == 1)
		str = ft_strdup("");
	else
		str = ft_itoa(num);
	isnegative = num >= 0 ? 0 : 1;
	len = num == -2147483648 ? 11 : (int)ft_strlen(str);
	ft_handle_d_star(obj);
	if (isnegative)
	{
		num *= -1;
		free(str);
		str = ft_itoa(num);
	}
	ft_handle_d_left(obj, len, isnegative, minus);
	ft_handle_d_right(obj, len, isnegative, &str);
	free(str);
}
