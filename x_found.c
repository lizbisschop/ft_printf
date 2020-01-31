/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   x_found.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 12:09:34 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/30 17:26:20 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_second(t_fl *fl, char *hexa_str, int count, int minus_print)
{
	hexa_str[count] = '\0';
	if (((unsigned long)fl->arg == 0))
		hexa_str[0] = '0';
	if (fl->pre == 0 && fl->wdth != 0)
		fl->padd = ' ';
	hexa_str = ft_str_reverse(hexa_str);
	implement_width_d_i(&(*fl), hexa_str, minus_print);
	if (fl->pre != 0 || (fl->pre == 0 && (unsigned long)fl->arg != 0))
		ft_putstr_pf(hexa_str, &(*fl));
	implement_width_d_i(&(*fl), hexa_str, minus_print);
	free(hexa_str);
}

int		x_loop(unsigned long nb, char **hexa_str, char x)
{
	int temp;
	int count;

	temp = nb;
	count = 0;
	while (nb > 0)
	{
		temp = nb % 16;
		nb = nb / 16;
		if (temp < 10)
			(*hexa_str)[count] = temp + 48;
		else if (temp >= 10 && x == 'X')
			(*hexa_str)[count] = temp + 55;
		else if (temp >= 10 && x == 'x')
			(*hexa_str)[count] = temp + 87;
		count++;
	}
	return (count);
}

int		x_found(unsigned long nb, char x, t_fl *fl)
{
	int		minus_printed;
	char	*hexa_str;
	int		count;

	count = 0;
	minus_printed = 0;
	hexa_str = ft_calloc(14, 8);
	if (!hexa_str)
		return (-1);
	count = x_loop(nb, &hexa_str, x);
	x_second(&(*fl), hexa_str, count, minus_printed);
	return (0);
}
