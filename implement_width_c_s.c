/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   implement_width_c_s.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:04:23 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/27 16:22:15 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	implement_width_c(t_fl *fl)
{
	int		i;

	if (fl->zero > 0 && fl->minus > 0)
		fl->zero = 0;
	if (fl->zero == 0)
		fl->padd = ' ';
	i = 1;
	while (fl->wdth > i)
	{
		write(1, &fl->padd, 1);
		fl->ret_printf++;
		fl->wdth--;
	}
	fl->wdth = 0;
}

int		implement_width_s(t_fl *fl)
{
	char	*string_arg;
	int		i;

	string_arg = NULL;
	if (checking_and_setting_s(&(*fl), &i, &string_arg) == -1)
		return (-1);
	while (fl->wdth > i)
	{
		write(1, &fl->padd, 1);
		fl->ret_printf++;
		fl->wdth--;
	}
	fl->wdth = 0;
	if (string_arg)
		free(string_arg);
	return (0);
}
