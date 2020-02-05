/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_loop.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/04 15:20:20 by lbisscho       #+#    #+#                */
/*   Updated: 2020/02/04 15:20:38 by lbisscho      ########   odam.nl         */
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
