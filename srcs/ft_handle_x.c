/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:41:34 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:10 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_lpx(int len, t_flags **obj)
{
	if ((*obj)->dot && (*obj)->precision - len > 0)
	{
		if ((*obj)->width - len - ((*obj)->precision - len) > 0 &&
				!(*obj)->minus)
		{
			if ((*obj)->zero && !(*obj)->dot)
				(*obj)->result_length += ft_putchar_zero((*obj)->width - len -
						((*obj)->precision - len));
			else
				(*obj)->result_length += ft_putchar_space((*obj)->width - len -
						((*obj)->precision - len));
		}
		(*obj)->result_length += ft_putchar_zero((*obj)->precision - len);
	}
}

void	ft_handle_lwx(int len, t_flags **obj)
{
	if ((*obj)->width > 0 && ((*obj)->width - len -
				((*obj)->precision - len)) > 0 && !(*obj)->minus)
	{
		if (!((*obj)->precision - len > 0) && (*obj)->width - len > 0)
		{
			if ((*obj)->zero)
			{
				if (!(*obj)->dot)
					(*obj)->result_length +=
						ft_putchar_zero((*obj)->width - len);
				else
					(*obj)->result_length +=
						ft_putchar_space((*obj)->width - len);
			}
			else
				(*obj)->result_length +=
					ft_putchar_space((*obj)->width - len);
		}
	}
}

void	ft_handle_rx(int len, t_flags **obj)
{
	if ((*obj)->width > 0 && ((*obj)->width - len) > 0 && (*obj)->minus)
	{
		if (!(*obj)->dot)
			(*obj)->result_length += ft_putchar_space((*obj)->width - len);
		else
		{
			if ((*obj)->precision > len &&
					(*obj)->width - (*obj)->precision > 0)
				(*obj)->result_length +=
					ft_putchar_space((*obj)->width - (*obj)->precision);
			else if ((*obj)->width - len - ((*obj)->precision - len) > 0)
				(*obj)->result_length +=
					ft_putchar_space((*obj)->width - len);
		}
	}
}

int		ft_check_bonus(t_flags **obj)
{
	if (ft_strchr((*obj)->modifiers, 'l') != NULL ||
			ft_strchr((*obj)->modifiers, 'h') != NULL ||
			ft_strchr((*obj)->modifiers, '#') != NULL)
		return (0);
	else
		return (1);
}

void	ft_handle_x(va_list *ap, t_flags **obj, int maj)
{
	unsigned int	num;
	char			*str;
	int				len;
	int				zero;

	num = (unsigned int)(va_arg(*ap, unsigned int));
	if (!ft_check_bonus(obj))
		return ;
	str = ft_itoa_base(num, 16, maj);
	len = (int)ft_strlen(str);
	zero = 0;
	if ((*obj)->dot)
	{
		zero = ft_strncmp(str, "0", 1) == 0 ? 1 : 0;
		zero == 1 ? len -= 1 : 0;
	}
	ft_handle_lpx(len, obj);
	ft_handle_lwx(len, obj);
	if (zero == 0)
	{
		ft_putstr_fd(str, 1);
		(*obj)->result_length += len;
	}
	ft_handle_rx(len, obj);
	free(str);
}
