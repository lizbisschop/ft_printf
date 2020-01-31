/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   implement_precisions.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 16:53:18 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/30 16:53:39 by lbisscho      ########   odam.nl         */
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
