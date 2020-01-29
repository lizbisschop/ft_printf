/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/06 11:08:22 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/29 18:14:12 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

typedef	struct	s_fl
{
	int			count;
	int			wdth;
	char		padd;
	int			ret_printf;
	void		*arg;
	int			minus;
	int			zero;
	int			pre;
	int			check;
	int			c_d_i;
	int			c_x;
	int			c_p;
	int			fl_exst;
	int			save_width;
	int			save_pre;
	int			wdth_cnt;
	int			pre_exist;
	int			c;
}				t_fl;

int				ft_printf(const char *format, ...);
int				percent_found(t_fl *fl, const char *format, va_list ap);
void			set_flags_zero(t_fl *fl);
int				c_s_found(t_fl *fl, char cha);
int				implement_width_s(t_fl *fl);
void			flags_detected(t_fl *fl, const char *format);
void			implement_width_d_i(t_fl *fl, char *str_arg, int minus_printed);
int				checking_and_setting_s(t_fl *fl, int *i, char **string_arg);
int				d_i_found(t_fl *fl);
int				x_found(unsigned long nb, char x, t_fl *fl);
char			*ft_str_reverse(char *string);
int				p_found(t_fl *fl);
void			implement_width(t_fl *fl);
void			implement_width_percent(t_fl *fl);
void			ft_putstr_pf(char *s, t_fl *fl);
void			ft_putnbr_pf(int n, t_fl *fl);
void			ft_putchar_pf(char c, t_fl *fl);
void			implement_precision(t_fl *fl, int i);
void			implement_precision_d_i(t_fl *fl, int i, char *str_arg);
int				u_found(t_fl *fl);
int				len(long nb);
char			*ft_itoa_pf(unsigned long n);
int				ft_strlen_pf(char *str);
void			second_percent(t_fl *fl);
void			implement_precision_p(t_fl *fl, int i);
void			implement_width_p(t_fl *fl, char *str_arg);
int				s_found(t_fl *fl);
void			c_found(t_fl *fl);
void			implement_width_c(t_fl *fl);
void			check_nbr(t_fl *fl, const char *format);
void			check_star(t_fl *fl, const char *format, va_list ap);
int				check_conversions_2(t_fl *fl, const char *format);
int				check_conversion(t_fl *fl, const char *format);
void			check_and_set(t_fl *fl, int *i, int *minus, char *str_arg);
void			while_loop_d_i(t_fl *fl, int *i);
int				check_if_conversions_exist(const char *format);
int				ft_printf_loop(t_fl *fl, const char *format, va_list ap);
int				power(int base, int digit);
void			p_second(t_fl *fl, char *pointer_str);
void			checking_and_setting_p(t_fl *fl, char *str_arg, int *i);
void			x_second(t_fl *fl, char *hexa_str, int count, int minus_print);
int				x_loop(unsigned long nb, char **hexa_str, char x);

#endif
