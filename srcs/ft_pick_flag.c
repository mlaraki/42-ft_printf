/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pick_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 16:42:03 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:15 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pick_flag(va_list *ap, t_flags **obj)
{
	int len;

	len = (int)ft_strlen((*obj)->modifiers) - 1;
	if ((*obj)->modifiers[len] == 'c')
		ft_handle_c(ap, obj);
	else if ((*obj)->modifiers[len] == '%')
		ft_handle_percent(obj);
	else if ((*obj)->modifiers[len] == 's')
		ft_handle_s(ap, obj);
	else if ((*obj)->modifiers[len] == 'p')
		ft_handle_p(ap, obj);
	else if ((*obj)->modifiers[len] == 'd' || (*obj)->modifiers[len] == 'i')
		ft_handle_d(ap, obj);
	else if ((*obj)->modifiers[len] == 'u')
		ft_handle_u(ap, obj);
	else if ((*obj)->modifiers[len] == 'x')
		ft_handle_x(ap, obj, 0);
	else if ((*obj)->modifiers[len] == 'X')
		ft_handle_x(ap, obj, 1);
}
