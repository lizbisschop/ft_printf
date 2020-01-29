/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags_detected.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:53:01 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 17:34:15 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_detected(t_fl *fl, const char *format)
{
	if (format[fl->count] == '0')
	{
		fl->padd = '0';
		fl->zero = 1;
		fl->fl_exst = 1;
	}
	if (format[fl->count] == '-')
	{
		fl->minus = 1;
		fl->fl_exst = 1;
	}
}
