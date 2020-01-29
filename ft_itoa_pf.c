/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_pf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:11:12 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 17:11:49 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len(long nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_pf(unsigned long n)
{
	char			*str;
	unsigned long	num;
	unsigned long	i;

	num = n;
	i = len(num);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = '\0';
	i--;
	if (num < 0)
	{
		str[0] = '-';
		num = num * -1;
	}
	while (num > 9)
	{
		str[i] = 48 + (num % 10);
		num = num / 10;
		i--;
	}
	str[i] = 48 + num;
	return (str);
}
