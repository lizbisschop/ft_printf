/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:43:43 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/27 14:43:10 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_loop(t_fl *fl, const char *format, va_list ap)
{
	if (format[fl->count] == '%')
	{
		if (format[fl->count + 1] != '%')
			fl->arg = va_arg(ap, void *);
		if (format[fl->count + 1] == '%')
		{
			ft_putchar_pf('%', &(*fl));
			fl->count = fl->count + 1;
		}
		else
		{
			fl->count++;
			if (percent_found(&(*fl), format, ap) == -1)
				return (-1);
		}
	}
	else
		ft_putchar_pf(format[fl->count], &(*fl));
	fl->count++;
	return (0);
}

int		ft_printf(const char *format, ...)
{
	t_fl	fl;
	va_list ap;

	va_start(ap, format);
	fl.count = 0;
	fl.ret_printf = 0;
	while (format[fl.count] != '\0')
	{
		if (ft_printf_loop(&fl, format, ap) == -1)
			return (-1);
	}
	va_end(ap);
	return (fl.ret_printf);
}
