/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:10:17 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/05 13:09:17 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_append_modifiers(t_flags **obj, char c)
{
	char	*str;
	size_t	len;

	len = ft_strlen((*obj)->modifiers);
	if (!(str = (char *)malloc(len + 2)))
		return (-1);
	ft_strncpy(str, (*obj)->modifiers, len);
	str[len] = c;
	str[len + 1] = '\0';
	free((*obj)->modifiers);
	(*obj)->modifiers = ft_strdup(str);
	free(str);
	return (1);
}

void	ft_set_modifiers(t_flags **obj)
{
	if (ft_strchr((*obj)->modifiers, '-') != NULL)
		(*obj)->minus = 1;
	if (ft_strchr((*obj)->modifiers, '.') != NULL)
		(*obj)->dot = 1;
	if (ft_strchr((*obj)->modifiers, '*') != NULL)
		(*obj)->star = 1;
}

void	ft_get_width(va_list *ap, t_flags **obj, int i)
{
	while ((*obj)->modifiers[i++] != '\0')
	{
		if ((*obj)->modifiers[i] == '*')
		{
			(*obj)->width = va_arg(*ap, int);
			if ((*obj)->width < 0)
			{
				(*obj)->minus = 1;
				(*obj)->width *= -1;
			}
			break ;
		}
		if ((*obj)->modifiers[i] == '.')
			break ;
		if ((*obj)->modifiers[i] >= '0' && (*obj)->modifiers[i] <= '9')
		{
			if ((*obj)->modifiers[i] == '0')
				if (ft_strchr("123456789*", (*obj)->modifiers[i + 1]))
					(*obj)->zero = 1;
			(*obj)->width *= 10;
			(*obj)->width += (*obj)->modifiers[i] - 48;
		}
	}
}

void	ft_get_precision(va_list *ap, t_flags **obj)
{
	int i;

	i = 0;
	while ((*obj)->modifiers[i] != '.' && (*obj)->modifiers[i] != '\0')
		i++;
	if ((*obj)->modifiers[i + 1] == '*')
	{
		(*obj)->precision = va_arg(*ap, int);
		if ((*obj)->precision < 0)
		{
			(*obj)->dot = 0;
			(*obj)->precision = 0;
		}
	}
	while ((*obj)->modifiers[i + 1] >= '0' && (*obj)->modifiers[i + 1] <= '9')
	{
		(*obj)->precision *= 10;
		(*obj)->precision += (*obj)->modifiers[i + 1] - 48;
		i++;
	}
}

int		ft_append_flag(va_list *ap, t_flags **obj, const char **format,
		int position)
{
	int		i;
	int		j;
	char	*temp;

	ft_init_modifiers(obj);
	temp = ft_strdup(*format);
	position++;
	i = 0;
	j = 0;
	while (ft_strchr("cspdiouxXfyb%#-+ .*0123456789hLljz", temp[position])
			!= NULL && temp[position] != '\0')
	{
		ft_append_modifiers(obj, temp[position]);
		if (ft_strchr("cspdiouxXfyb%", temp[position]))
			break ;
		position++;
	}
	ft_set_modifiers(obj);
	ft_get_width(ap, obj, j);
	ft_get_precision(ap, obj);
	ft_pick_flag(ap, obj);
	free(temp);
	return (position);
}
