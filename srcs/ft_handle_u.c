/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:34:25 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:08 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_left(t_flags **obj, int len)
{
	if (((*obj)->width - len) > 0)
	{
		if (!(*obj)->minus)
		{
			if ((*obj)->zero == 1 && (*obj)->dot == 0)
				(*obj)->result_length += ft_putchar_zero((*obj)->width - len);
			else
			{
				if ((*obj)->dot)
				{
					if ((*obj)->precision < len)
						(*obj)->result_length +=
							ft_putchar_space((*obj)->width - len);
					else if ((*obj)->width - (*obj)->precision > 0)
						(*obj)->result_length +=
							ft_putchar_space((*obj)->width - (*obj)->precision);
				}
				else if (!(*obj)->dot && (*obj)->width - len > 0)
					(*obj)->result_length +=
						ft_putchar_space((*obj)->width - len);
			}
		}
	}
}

void	ft_put_u(t_flags **obj, int len, char **str)
{
	if ((*obj)->precision - len > 0)
	{
		ft_putchar_zero((*obj)->precision - len);
		(*obj)->result_length += (*obj)->precision - len;
	}
	ft_putstr_fd(*str, 1);
	(*obj)->result_length += len;
}

void	ft_put_right(t_flags **obj, int len)
{
	if (((*obj)->width - len) > 0)
	{
		if ((*obj)->minus)
		{
			if ((*obj)->precision < len)
			{
				ft_putchar_space((*obj)->width - len);
				(*obj)->result_length += (*obj)->width - len;
			}
			else if ((*obj)->width - (*obj)->precision > 0)
			{
				ft_putchar_space((*obj)->width - (*obj)->precision);
				(*obj)->result_length += (*obj)->width - (*obj)->precision;
			}
		}
	}
}

void	ft_handle_u(va_list *ap, t_flags **obj)
{
	int		num;
	int		len;
	char	*str;
	int		minus;

	minus = 0;
	num = (unsigned int)va_arg(*ap, unsigned int);
	if (ft_strchr((*obj)->modifiers, 'l') != NULL ||
			ft_strchr((*obj)->modifiers, 'h') != NULL)
		return ;
	if (num == 0 && (*obj)->dot == 1)
		str = ft_strdup("");
	else
		str = ft_itoa_u(num);
	len = (int)ft_strlen(str);
	if ((*obj)->star && (*obj)->precision_minus)
		(*obj)->precision *= -1;
	if ((*obj)->star && (*obj)->width < 0)
		(*obj)->width *= -1;
	ft_put_left(obj, len);
	ft_put_u(obj, len, &str);
	ft_put_right(obj, len);
	free(str);
}
