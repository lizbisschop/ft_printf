/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:08:22 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/11 14:27:01 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <string.h>
# include "./libft/libft.h"

typedef	struct	s_flags
{
	int			count;
	size_t		width;
	char		padding;
	size_t		ret_printf;
	void		*arg;
	char		*string;
	int			minus;
	int			zero;
	int			precision;
	int			star;
	int			c;
}				t_flags;

int				ft_printf(const char *configs, ...);
void			flags_detected(t_flags *flags, const char *format);
void			s_found(t_flags flags);
void			percent_found(t_flags *flags, const char *format, va_list ap);
void			c_found(t_flags flags);
void			d_i_found(t_flags flags);
void			check_width(t_flags *flags_checked, const char *format, int i);
int				ft_strlen_printf(char *string);
void			set_flags_zero(t_flags *flags);
void			implement_width_s_c(t_flags *flags);

#endif

                         