/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft_put.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:34:08 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 17:12:38 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen_pf(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_pf(char c, t_fl *fl)
{
	write(1, &c, 1);
	fl->ret_printf++;
}

void	ft_putnbr_pf(int n, t_fl *fl)
{
	if (n == -2147483648)
	{
		ft_putchar_pf('2', &(*fl));
		ft_putnbr_pf(147483648, &(*fl));
	}
	else if (n < 0)
		ft_putnbr_pf((n * -1), &(*fl));
	else if (n >= 10)
	{
		ft_putnbr_pf(n / 10, &(*fl));
		ft_putchar_pf(n % 10 + '0', &(*fl));
	}
	else
		ft_putchar_pf(n + '0', &(*fl));
}

void	ft_putstr_pf(char *s, t_fl *fl)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_pf(s[i], &(*fl));
			i++;
		}
	}
}

char	*ft_str_reverse(char *string)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = ft_strlen(string) - 1;
	while (i < j)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		i++;
		j--;
	}
	return (string);
}
