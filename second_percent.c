/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   second_percent.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 16:38:36 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/30 11:51:50 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	second_percent(t_fl *fl)
{
	char	*str_arg;
	int		minus_printed;

	if (fl->pre != -1)
	{
		fl->pre = -1;
		fl->save_pre = -1;
	}
	minus_printed = 0;
	str_arg = "%";
	implement_width_d_i(&(*fl), str_arg, minus_printed);
	ft_putchar_pf('%', &(*fl));
	implement_width_d_i(&(*fl), str_arg, minus_printed);
}
