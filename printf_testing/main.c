/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 11:58:33 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/11 14:36:41 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int i;

	i = 4;
	ft_printf("mine: %23.12d|\n", 23);
	printf("real: %23.12d|\n", 23);
	return (0);
}
