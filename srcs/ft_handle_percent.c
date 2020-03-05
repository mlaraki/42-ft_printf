/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:58:22 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/03 14:23:05 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_percent(t_flags **obj)
{
	int count;

	count = (*obj)->width - 1;
	if ((*obj)->width > 1 && (*obj)->minus == 0)
	{
		if ((*obj)->zero == 1)
		{
			ft_putchar_zero(count);
			(*obj)->result_length += count;
		}
		else
		{
			ft_putchar_space(count);
			(*obj)->result_length += count;
		}
	}
	ft_putchar_fd('%', 1);
	(*obj)->result_length += 1;
	if ((*obj)->width > 1 && (*obj)->minus == 1)
	{
		ft_putchar_space(count);
		(*obj)->result_length += count;
	}
}
