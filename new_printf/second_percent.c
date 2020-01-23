/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   second_percent.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 16:38:36 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 17:08:16 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags_zero(t_fl *fl)
{
	fl->wdth = 0;
	fl->minus = 0;
	fl->zero = 0;
	fl->pre = -1;
	fl->star = 0;
	fl->check = 0;
	fl->c_d_i = 0;
	fl->c = 0;
	fl->save_pre = -1;
	fl->c_x = 0;
	fl->c_p = 0;
	fl->fl_exst = 0;
	fl->save_width = 0;
	fl->wdth_cnt = 0;
	fl->pre_exist = 0;
	fl->padd = ' ';
}

int		check_if_conversions_exist(const char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == 'c' || format[i] == 's')
			return (0);
		else if (format[i] == 'd' || format[i] == 'i')
			return (0);
		else if (format[i] == 'x' || format[i] == 'X')
			return (0);
		else if (format[i] == 'p' || format[i] == 'u')
			return (0);
		else if (format[i] == '%')
			return (0);
		i++;
	}
	return (1);
}

void	second_percent(t_fl *fl)
{
	char	*str_arg;
	int		minus_printed;

	minus_printed = 0;
	str_arg = "%";
	implement_width_d_i(&(*fl), str_arg, minus_printed);
	ft_putchar_pf('%', &(*fl));
	implement_width_d_i(&(*fl), str_arg, minus_printed);
}
