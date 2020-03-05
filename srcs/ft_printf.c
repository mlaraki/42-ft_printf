/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:47:30 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/05 13:01:28 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_loop(t_flags **obj, va_list *ap, const char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%' && format[i])
		{
			write(1, &format[i], 1);
			(*obj)->result_length++;
		}
		else if (format[i] == '%')
		{
			if ((*obj)->init_mod)
				ft_reset_modifiers(obj);
			if (!ft_strchr("cspdiouxXfyb%#-+. *0123456789hLljz", format[i + 1]))
				break ;
			i = ft_append_flag(ap, obj, &format, i);
		}
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_flags *obj;
	va_list ap;

	if (!(obj = (t_flags *)malloc(sizeof(t_flags))))
		return (-1);
	va_start(ap, format);
	ft_init_struct(&obj);
	if ((ft_strchr(format, '%') == NULL))
	{
		ft_putstr_fd((char *)format, 1);
		ft_clear(&ap, &obj);
		return (ft_strlen(format));
	}
	if ((int)ft_strlen(format) == 1 && format[0] == '%')
		return (0);
	ft_loop(&obj, &ap, format);
	ft_clear(&ap, &obj);
	return (obj->result_length);
}
