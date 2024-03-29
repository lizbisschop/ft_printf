/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 11:43:43 by lbisscho       #+#    #+#                */
/*   Updated: 2020/02/04 15:25:44 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
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
