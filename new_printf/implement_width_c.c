/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   implement_width_c.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:04:23 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 17:04:32 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	implement_width_c(t_fl *fl)
{
	char	*string_arg;
	int		i;

	if (fl->zero > 0 && fl->minus > 0)
		fl->zero = 0;
	if (fl->zero == 0)
		fl->padd = ' ';
	if (fl->c == 1)
		i = 1;
	else
	{
		string_arg = ft_strdup((char *)fl->arg);
		if (ft_strlen_pf(string_arg) > fl->pre && fl->pre != -1)
			i = fl->pre;
		else
			i = ft_strlen_pf(string_arg);
	}
	while (fl->wdth > i)
	{
		write(1, &fl->padd, 1);
		fl->ret_printf++;
		fl->wdth--;
	}
	fl->wdth = 0;
}
