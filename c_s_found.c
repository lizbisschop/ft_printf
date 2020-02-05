/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   c_s_found.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 15:52:46 by lbisscho       #+#    #+#                */
/*   Updated: 2020/02/03 13:56:55 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		checking_and_setting_s(t_fl *fl, int *i, char **string_arg)
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
		if (!*string_arg)
			return (-1);
		if (ft_strlen_pf(*string_arg) > fl->pre && fl->pre != -1)
			*i = fl->pre;
		else
			*i = ft_strlen_pf(*string_arg);
	}
	return (0);
}

void	c_found(t_fl *fl)
{
	fl->c = 1;
	if (fl->minus == 0 && fl->wdth != 0)
		implement_width_c(&(*fl));
	if (fl->pre == -1)
		ft_putchar_pf((char)fl->arg, &(*fl));
	if (fl->minus > 0)
		implement_width_c(&(*fl));
}

int		s_second(t_fl *fl, char **newstr)
{
	if (fl->arg == NULL)
	{
		if (fl->pre != -1)
			*newstr = ft_substr("(null)", 0, fl->pre);
		else
			*newstr = ft_strdup("(null)");
		if (!*newstr)
			return (-1);
		ft_putstr_pf(*newstr, &(*fl));
	}
	else if (fl->pre == -1)
	{
		*newstr = ft_strdup((char *)fl->arg);
		if (!newstr)
			return (-1);
		ft_putstr_pf(*newstr, &(*fl));
	}
	else if (fl->pre > 0)
	{
		*newstr = ft_substr((char *)fl->arg, 0, fl->pre);
		if (!newstr)
			return (-1);
		ft_putstr_pf(*newstr, &(*fl));
	}
	return (0);
}

int		s_found(t_fl *fl)
{
	char *newstr;

	newstr = NULL;
	if (fl->minus == 0 && fl->wdth != 0)
		implement_width_s(&(*fl));
	if (s_second(&(*fl), &newstr) == -1)
		return (-1);
	if (fl->minus > 0)
		implement_width_s(&(*fl));
	if (newstr)
		free(newstr);
	return (0);
}

int		c_s_found(t_fl *fl, char cha)
{
	if (cha == 'c')
	{
		if (fl->pre != -1)
			fl->pre = -1;
		c_found(&(*fl));
	}
	if (cha == 's')
	{
		if (s_found(&(*fl)) == -1)
			return (-1);
	}
	return (0);
}
