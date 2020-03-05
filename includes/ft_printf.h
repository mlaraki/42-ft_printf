/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaraki <mlaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 18:01:45 by mlaraki           #+#    #+#             */
/*   Updated: 2020/03/05 13:16:16 by mlaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct		s_flags
{
	char			*modifiers;
	int				precision;
	int				width;
	int				minus;
	int				plus;
	int				zero;
	int				dot;
	int				star;
	int				space;
	int				init_mod;
	int				result_length;
	int				precision_minus;

}					t_flags;

void				ft_init_struct(t_flags **obj);
void				ft_clear(va_list *ap, t_flags **obj);
char				*ft_strncat(char *dest, const char *src, int n);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strnew(size_t size);
char				*ft_itoa_u(unsigned int n);
char				*ft_itoa_base(unsigned long long value,
						unsigned long long base, int maj);
void				ft_init_modifiers(t_flags **obj);
int					ft_append_flag(va_list *ap, t_flags **obj,
						const char **format, int position);
void				ft_reset_modifiers(t_flags **obj);
int					ft_putchar_zero(int count);
int					ft_putchar_space(int count);
void				ft_handle_c(va_list *ap, t_flags **obj);
void				ft_handle_s(va_list *ap, t_flags **obj);
void				ft_handle_percent(t_flags **obj);
void				ft_handle_d(va_list *ap, t_flags **obj);
int					ft_handle_d_minus(int isnegative, int printed);
int					ft_handle_d_left(t_flags **obj, int len,
						int isnegative, int minus);
int					ft_handle_d_left2(t_flags **obj, int len,
						int isnegative, int minus);
void				ft_handle_u(va_list *ap, t_flags **obj);
void				ft_handle_p(va_list *ap, t_flags **obj);
void				ft_handle_x(va_list *ap, t_flags **obj, int maj);
void				ft_pick_flag(va_list *ap, t_flags **obj);
int					ft_printf(const char *format, ...);

#endif
