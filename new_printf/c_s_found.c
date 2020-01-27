/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_s_found.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 15:52:46 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/27 13:32:31 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	checking_and_setting_s(t_fl *fl, int *i, char **string_arg)
{
	if (fl->zero > 0 && fl->minus > 0)
		fl->zero = 0;
	if (fl->zero == 0)
		fl->padd = ' ';
	if (fl->c == 1)
		*i = 1;
	if ((fl->arg == NULL && fl->pre == -1) || (fl->arg == NULL &&
		fl->pre > ft_strlen_pf(("(null)"))))
		*i = ft_strlen("(null)");
	else if (fl->arg == NULL && fl->pre >= 0)
		*i = fl->pre;
	else
	{
		*string_arg = ft_strdup((char *)fl->arg);
		if (ft_strlen_pf(*string_arg) > fl->pre && fl->pre != -1)
			*i = fl->pre;
		else
			*i = ft_strlen_pf(*string_arg);
	}
}

void	implement_width_s(t_fl *fl)
{
	char	*string_arg;
	int		i;

	string_arg = NULL;
	checking_and_setting_s(&(*fl), &i, &string_arg);
	while (fl->wdth > i)
	{
		write(1, &fl->padd, 1);
		fl->ret_printf++;
		fl->wdth--;
	}
	fl->wdth = 0;
	if (string_arg)
		free(string_arg);
}

void	c_found(t_fl *fl)
{
	if (fl->pre == 0)
		return ;
	fl->c = 1;
	if (fl->minus == 0 && fl->wdth != 0)
		implement_width_c(&(*fl));
	if (fl->pre == -1)
		ft_putchar_pf((char)fl->arg, &(*fl));
	if (fl->minus > 0)
		implement_width_c(&(*fl));
}

void	s_found(t_fl *fl)
{
	char *newstr;

	newstr = NULL;
	if (fl->minus == 0 && fl->wdth != 0)
		implement_width_s(&(*fl));
	if (fl->arg == NULL)
	{
		newstr = ft_substr("(null)", 0, fl->pre);
		ft_putstr_pf(newstr, &(*fl));
	}
	else if (fl->pre == -1)
	{
		newstr = ft_strdup((char *)fl->arg);
		ft_putstr_pf(newstr, &(*fl));
	}
	else if (fl->pre > 0)
	{
		newstr = ft_substr((char *)fl->arg, 0, fl->pre);
		ft_putstr_pf(newstr, &(*fl));
	}
	if (fl->minus > 0)
		implement_width_s(&(*fl));
	if (newstr)
		free(newstr);
}

void	c_s_found(t_fl *fl, char cha)
{
	if (cha == 'c')
		c_found(&(*fl));
	if (cha == 's')
		s_found(&(*fl));
}
