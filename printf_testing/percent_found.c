/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percent_found.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:27:04 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/11 14:42:26 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags_zero(t_flags *flags)
{
	flags->minus = 0;
	flags->precision = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->star = 0;
	flags->width = 0;
	flags->c = 0;
}

void	implement_width_s_c(t_flags *flags)
{
	char *string_arg;
	size_t i;
	
	if (flags->zero == 0)
		flags->padding = ' ';
	if (flags->c == 1)
	{
		string_arg = malloc(2);
		string_arg[0] = flags->c;
		string_arg[1] = '\0';
	}
	else
		string_arg = ft_strdup((char *)flags->arg);
	i = ft_strlen(string_arg);
	while (flags->width > i)
	{
		write(1, &flags->padding, 1);
		flags->width--;
	}
	flags->width = 0;
}

void	implement_width_d_i(t_flags *flags)
{
	char *str_arg;
	size_t length;

	if (flags->zero == 0)
		flags->padding = ' ';
	if (flags->precision > 0)
		flags->padding = '0';
	str_arg = ft_itoa((size_t)flags->arg);
	length = ft_strlen(str_arg);
	while (flags->width > length && flags->width > flags->precision)
	{
		write(1, &flags->padding, 1);
		flags->width--;
	}
	flags->width = 0;
}

void	percent_found(t_flags *flags, const char * format, va_list ap)
{
	set_flags_zero(&(*flags));
	int check;

	check = 0;
	while (format[flags->count] != '\0' && format[flags->count] != '%')
	{
		if (format[flags->count] == '*')
		{
			flags->width = (size_t)flags->arg;
			flags->arg = va_arg(ap, void *);
		}
		else if (format[flags->count] == 'c')
		{
			flags->c = 1;
			if (flags->minus == 0)
				implement_width_s_c(&(*flags));
			ft_putchar_fd((char)flags->arg, 1);
			if (flags->minus > 0)
				implement_width_s_c(&(*flags));
			return ;
		}
		else if (format[flags->count] == 's')
		{
			if (flags->minus == 0 && flags->precision == 0)
				implement_width_s_c(&(*flags));
			ft_putstr_fd((char *)flags->arg, 1);
			if (flags->minus > 0 && flags->precision == 0)
				implement_width_s_c(&(*flags));
			return ;
		}
		else if (format[flags->count] == 'd' || format[flags->count] == 'i')
		{
			if (flags->minus == 0)
				implement_width_d_i(&(*flags));
			ft_putnbr_fd((int)flags->arg, 1);
			// if (check == 1)
			// 	flags->arg = ft_itoa((int)flags->arg);
			if (flags->minus > 0)
				implement_width_d_i(&(*flags));
			return ;
		}
		else if (format[flags->count] >= '0' && format[flags->count] <= '9' && check == 0)
		{
			flags->padding = ' ';
			flags_detected(&(*flags), format);
			check = 1;
			if (flags->width == 0)
				flags->width = ft_atoi(&format[flags->count]);
		}
		else if (format[flags->count] == '.')
		{
			flags->precision = ft_atoi(format);
		}
		else if (check != 1)
			flags_detected(&(*flags), format);
		flags->count++;
	}
}
