/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_detected.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:53:01 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/11 14:25:46 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_printf(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

void	flags_detected(t_flags *flags, const char *format)
{
	if (format[flags->count] == '0')
	{
		flags->padding = '0';
		flags->zero = 1;
	}
	else flags->padding = ' ';
	if (format[flags->count] == '-')
		flags->minus = 1;
	else if (format[flags->count] == '.')
	{
		flags->precision = 1;
		flags->width = ft_atoi(format);
	}
	// flags->count++;
	// if (format[flags->count] >= '0' && format[flags->count] <= '9')
	// {
	// 	flags->width = ft_atoi(&format[flags->count]);
	// 	*check = 1;
	// }
}