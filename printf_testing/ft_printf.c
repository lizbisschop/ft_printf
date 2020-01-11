/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:21:21 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/11 13:34:06 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_flags flags;
	va_list ap;
	va_start(ap, format);
	flags.count = 0;
	while(format[flags.count] != '\0')
	{
		if (format[flags.count] == '%')
		{
			flags.arg = va_arg(ap, void *);
			flags.count++;
			percent_found(&flags, format, ap);
		}
		else 
			write(1, &format[flags.count], 1);
		flags.count++;
	}
	va_end(ap);
	return (0);
}