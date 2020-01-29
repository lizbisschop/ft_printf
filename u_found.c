/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   u_found.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 16:51:52 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/29 12:42:28 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		u_found(t_fl *fl)
{
	int		minus_printed;
	char	*nb;

	minus_printed = 0;
	nb = ft_itoa_pf((unsigned long)fl->arg);
	if (!nb)
		return (-1);
	implement_width_d_i(&(*fl), nb, minus_printed);
	if (fl->pre != 0 || (fl->pre == 0 && (unsigned long)fl->arg) != 0)
		ft_putstr_pf(nb, &(*fl));
	implement_width_d_i(&(*fl), nb, minus_printed);
	if (nb)
		free(nb);
	return (0);
}
