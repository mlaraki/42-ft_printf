/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 15:17:48 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:07 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_s_nminus(t_flags **obj, char *str, int char_count)
{
	int i;

	i = 0;
	if ((*obj)->dot && char_count > (*obj)->precision)
		char_count = (*obj)->precision;
	if ((*obj)->width > char_count)
	{
		if ((*obj)->zero)
			ft_putchar_zero((*obj)->width - char_count);
		else
			ft_putchar_space((*obj)->width - char_count);
		(*obj)->result_length += (*obj)->width - char_count;
	}
	while (i < char_count)
	{
		ft_putchar_fd(str[i++], 1);
		(*obj)->result_length++;
	}
}

void	ft_handle_s_minus(t_flags **obj, char *str, int char_count)
{
	int i;

	i = 0;
	if ((*obj)->dot && char_count > (*obj)->precision)
		char_count = (*obj)->precision;
	while (i < char_count)
	{
		ft_putchar_fd(str[i++], 1);
		(*obj)->result_length++;
	}
	ft_putchar_space((*obj)->width - char_count);
	if ((*obj)->width - char_count > 0)
		(*obj)->result_length += (*obj)->width - char_count;
}

void	ft_handle_s(va_list *ap, t_flags **obj)
{
	char	*str;
	int		char_count;

	str = va_arg(*ap, char *);
	if (str == NULL || !str)
		str = "(null)";
	char_count = 0;
	if (str[0] != '\0')
		char_count = (int)ft_strlen(str);
	if ((*obj)->star && (*obj)->precision_minus)
		(*obj)->precision = char_count;
	if ((*obj)->minus)
		ft_handle_s_minus(obj, str, char_count);
	else
		ft_handle_s_nminus(obj, str, char_count);
}
