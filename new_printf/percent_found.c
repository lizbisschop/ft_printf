/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   percent_found.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:52:10 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 12:00:31 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_conversion(t_fl *fl, const char *format)
{
	if (format[fl->count] == '%')
	{
		second_percent(&(*fl));
		return (1);
	}
	else if (format[fl->count] == 'd' || format[fl->count] == 'i')
	{
		d_i_found(&(*fl));
		return (1);
	}
	else if (format[fl->count] == 'x' || format[fl->count] == 'X')
	{
		x_found((unsigned long)fl->arg, format[fl->count], &(*fl));
		return (1);
	}
	return (0);
}

int		check_conversions_2(t_fl *fl, const char *format)
{
	if (format[fl->count] == 'c' || format[fl->count] == 's')
	{
		c_s_found(&(*fl), format[fl->count]);
		return (1);
	}
	else if (format[fl->count] == 'p' || format[fl->count] == 'u')
	{
		if (format[fl->count] == 'u')
			u_found(&(*fl));
		else
			p_found(&(*fl));
		return (1);
	}
	return (0);
}

void	check_star(t_fl *fl, const char *format, va_list ap)
{
	if (format[fl->count] == '*')
	{
		fl->star = 1;
		fl->fl_exst = 1;
		if (format[fl->count - 1] == '.')
		{
			if ((int)fl->arg < 0)
				fl->pre = -1;
			else
				fl->pre = (int)fl->arg;
			fl->save_pre = fl->pre;
		}
		else
		{
			fl->wdth = (int)fl->arg;
			if (fl->wdth < 0)
			{
				fl->minus = 1;
				fl->wdth = fl->wdth * -1;
			}
			fl->save_width = fl->wdth;
		}
		fl->arg = va_arg(ap, void *);
	}
}

void	check_nbr(t_fl *fl, const char *format)
{
	if (format[fl->count] > '0' && format[fl->count] <= '9' && fl->check == 0)
	{
		fl->check = 1;
		if (fl->wdth == 0 && fl->pre == -1)
		{
			fl->wdth = ft_atoi(&format[fl->count]);
			fl->save_width = fl->wdth;
		}
	}
	else if (format[fl->count] == '.')
	{
		fl->pre_exist = 1;
		fl->fl_exst = 1;
		if (format[fl->count + 1] >= '0' && format[fl->count + 1] <= '9')
		{
			fl->pre = ft_atoi(&format[fl->count + 1]);
			fl->save_pre = fl->pre;
		}
		else
			fl->pre = 0;
	}
}

void	percent_found(t_fl *fl, const char *format, va_list ap)
{
	if (check_if_conversions_exist(&format[fl->count]) == 1)
		return ;
	set_flags_zero(&(*fl));
	while (format[fl->count] != '\0')
	{
		if (check_conversion(&(*fl), format) == 1)
			return ;
		else if (check_conversions_2(&(*fl), format) == 1)
			return ;
		check_star(&(*fl), format, ap);
		check_nbr(&(*fl), format);
		if (fl->check != 1)
			flags_detected(&*fl, format);
		fl->count++;
	}
}
