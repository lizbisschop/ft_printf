/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   d_i_found.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 13:22:19 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/29 15:58:05 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	implement_precision_d_i(t_fl *fl, int i, char *str_arg)
{
	if (str_arg[0] == '-' && fl->save_pre < fl->save_width)
		ft_putchar_pf('-', &(*fl));
	while (fl->pre > i)
	{
		ft_putchar_pf('0', &(*fl));
		fl->pre--;
		fl->wdth_cnt++;
	}
}

void	check_and_set(t_fl *fl, int *i, int *minus, char *str_arg)
{
	if (fl->zero > 0 && fl->minus > 0)
		fl->zero = 0;
	if ((fl->zero > 0 && fl->pre > 0) || fl->zero == 0)
		fl->padd = ' ';
	if (fl->pre > 0 && str_arg[0] == '-')
	{
		*minus = ft_strlen_pf(str_arg) - 1;
		if (fl->save_pre > ft_strlen_pf(str_arg))
			*i = ft_strlen(str_arg) + 2;
		else
			*i = ft_strlen_pf(str_arg);
	}
	else if (fl->pre == 0 && (int)fl->arg == 0)
		*i = 0;
	else
		*i = ft_strlen_pf(str_arg);
	if (fl->pre > fl->wdth)
		fl->wdth = 0;
}

void	while_loop_d_i(t_fl *fl, int *i)
{
	while (fl->wdth > fl->save_pre && fl->wdth > *i
		&& fl->wdth_cnt <= fl->save_width)
	{
		if ((fl->minus > 0 && fl->c_d_i == 0) ||
			(fl->c_d_i > 0 && fl->minus == 0))
			return ;
		ft_putchar_pf(fl->padd, &(*fl));
		fl->wdth--;
		fl->wdth_cnt++;
	}
}

void	implement_width_d_i(t_fl *fl, char *str_arg, int minus_printed)
{
	int i;
	int minus;

	check_and_set(&(*fl), &i, &minus, str_arg);
	if (fl->pre == -1 || fl->save_pre != fl->pre || fl->wdth > fl->pre)
		while_loop_d_i(&(*fl), &i);
	if ((fl->pre > 0 && fl->pre > minus) || (fl->pre > 0 && fl->pre > i))
	{
		if (str_arg[0] == '-')
			implement_precision_d_i(&(*fl), minus, str_arg);
		else
			implement_precision_d_i(&(*fl), i, str_arg);
	}
	else if (str_arg[0] == '-' && fl->save_pre <=
		fl->save_width && fl->c_d_i == 0 && minus_printed == 0)
		ft_putchar_pf('-', &(*fl));
	fl->c_d_i = 1;
}

int		d_i_found(t_fl *fl)
{
	char	*str_arg;
	int		minus_printed;

	minus_printed = 0;
	str_arg = ft_itoa((int)fl->arg);
	if (!str_arg)
		return (-1);
	if (str_arg[0] == '-' && fl->fl_exst > 0)
	{
		if (fl->save_pre > fl->save_width || fl->pre == -1)
		{
			ft_putchar_pf('-', &(*fl));
			minus_printed = 1;
		}
	}
	implement_width_d_i(&(*fl), str_arg, minus_printed);
	if (fl->pre != 0 || (fl->pre == 0 && (int)fl->arg != 0))
		ft_putnbr_pf((int)fl->arg, &(*fl));
	fl->wdth_cnt = fl->wdth_cnt + ft_strlen(str_arg);
	implement_width_d_i(&(*fl), str_arg, minus_printed);
	free(str_arg);
	return (0);
}
