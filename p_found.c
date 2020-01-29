/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   p_found.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 15:34:33 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/27 16:22:48 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checking_and_setting_p(t_fl *fl, char *str_arg, int *i)
{
	if (fl->zero > 0 && fl->minus > 0)
		fl->zero = 0;
	if ((fl->zero > 0 && fl->pre > 0) || fl->zero == 0)
		fl->padd = ' ';
	*i = ft_strlen(str_arg) + 2;
	if (fl->pre_exist == 1 && fl->arg == NULL)
		*i = 2;
	else if (fl->arg == NULL)
		*i = 3;
	if (fl->pre > fl->wdth)
		fl->wdth = 0;
}

void	implement_width_p(t_fl *fl, char *str_arg)
{
	int i;

	checking_and_setting_p(&(*fl), str_arg, &i);
	if (fl->pre == -1 || fl->save_pre != fl->pre || fl->wdth > fl->pre)
	{
		while (fl->wdth > fl->save_pre && fl->wdth
			> i && fl->wdth_cnt <= fl->save_width)
		{
			if ((fl->minus > 0 && fl->c_d_i == 0) ||
				(fl->c_d_i > 0 && fl->minus == 0))
				break ;
			ft_putchar_pf(fl->padd, &(*fl));
			fl->wdth--;
			fl->wdth_cnt++;
		}
	}
	if (fl->pre > 0)
		implement_precision_d_i(&(*fl), i, str_arg);
	fl->c_d_i = 1;
}

void	p_second(t_fl *fl, char *pointer_str)
{
	pointer_str = ft_str_reverse(pointer_str);
	implement_width_p(&(*fl), pointer_str);
	ft_putstr_pf("0x", &(*fl));
	if (fl->arg == NULL && fl->pre_exist == 0 && fl->save_pre == -1)
		ft_putchar_pf('0', &(*fl));
	else
		ft_putstr_pf(pointer_str, &(*fl));
	implement_width_p(&(*fl), pointer_str);
	free(pointer_str);
}

int		p_found(t_fl *fl)
{
	char			*pointer_str;
	unsigned long	nb;
	unsigned long	temp;
	int				i;

	i = 0;
	nb = (unsigned long)fl->arg;
	pointer_str = ft_calloc(14, 8);
	if (!pointer_str)
		return (-1);
	while (nb > 0)
	{
		temp = nb % 16;
		nb = nb / 16;
		if (temp < 10)
			pointer_str[i] = temp + 48;
		else if (temp >= 10)
			pointer_str[i] = temp + 87;
		i++;
	}
	pointer_str[i] = '\0';
	p_second(&(*fl), pointer_str);
	return (0);
}
