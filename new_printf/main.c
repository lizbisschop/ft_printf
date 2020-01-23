/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbisscho <lbisscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 11:58:33 by lbisscho       #+#    #+#                */
/*   Updated: 2020/01/23 16:31:38 by lbisscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// # define INPUT "mine: %3s|\n", "hello"

int	main(void)
{
	int i;
	int *p;

	i = 6;
	p = &i;


	// ft_printf("--------------THESE ARE NORMAL CONFERSIONS WITHOUT FLAGS----------------------\n");
	// ft_printf("mine: %s|\n", "string");
	// printf("real: %s|\n", "string");
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %u|\n", 1234456765);
	// printf("real: %u|\n", 1234456765);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %d|\n", 300);
	// printf("real: %d|\n", 300);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %x, %X|\n", 123455675, 123343254);
	// printf("real: %x, %X|\n", 123455675, 123343254);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %p|\n", p);
	// printf("real: %p|\n", p);
	// ft_printf("-------------THESE ARE ALL CONVERSIONS OF S WITH FLAGS------------------------\n");
	// ft_printf("mine: %-20s|\n", "string");
	// printf("real: %-20s|\n", "string");
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %20s|\n", "string");
	// printf("real: %20s|\n", "string");
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %*s|\n", 23, "string");
	// printf("real: %*s|\n", 23, "string");
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %.*s|\n", 23, "string");
	// printf("real: %.*s|\n", 23, "string");
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-30.20s|\n", "string");
	// printf("real: %-30.20s|\n", "string");
	// 	ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-20.30s|\n", "string");
	// printf("real: %-20.30s|\n", "string");
	// 	ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %20.8s|\n", "string");
	// printf("real: %20.8s|\n", "string");
	// 	ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %23.1s|\n", "string");
	// printf("real: %23.1s|\n", "string");
	// ft_printf("-------------THESE ARE ALL CONVERSIONS OF C WITH FLAGS------------------------\n");
	// ft_printf("mine: %-20c|\n", 'c');
	// printf("real: %-20c|\n", 'c');
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %20c|\n", 'c');
	// printf("real: %20c|\n", 'c');
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %*c|\n",  4 ,'c');
	// printf("real: %*c|\n", 4, 'c');
	// ft_printf("---------------THESE ARE ALL CONVERSIONS OF D OR I WITH FLAGS--------------------\n");
	// ft_printf("mine: %d|\n", 23);
	// printf("real: %d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %05d|\n", 23);
	// printf("real: %05d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-9d|\n", 23);
	// printf("real: %-9d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %.23d|\n", 23);
	// printf("real: %.23d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %.*d|\n", 25, 23);
	// printf("real: %.*d|\n", 25, 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-6.18d|\n", 23);
	// printf("real: %-6.18d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-15.5d|\n", 23);
	// printf("real: %-15.5d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-10.*d|\n", 15, 23);
	// printf("real: %-10.*d|\n", 15, 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %23.12d|\n", 12);
	// printf("real: %23.12d|\n", 12);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %023.30d|\n", 23);
	// printf("real: %023.30d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %023.12d|\n", 23);
	// printf("real: %023.12d|\n", 23);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("-----------------------THESE ARE ALL CONVERSION OF x OR X WITH FLAGS-------------\n");
	// ft_printf("mine: %23.12x|\n", 123456);
	// printf("real: %23.12x|\n", 123456);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %x|\n", 12345);
	// printf("real: %x|\n", 12345);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %.23X|\n", 12345);
	// printf("real: %.23X|\n", 12345);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %.*X|\n", 25, 12345);
	// printf("real: %.*X|\n", 25, 12345);
	// ft_printf("------------------------------------------------------------------------------\n");
	// ft_printf("mine: %-6.18x|\n", 12345);
	// printf("real: %-6.18x|\n", 12345);	
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %-15.5x|\n", 12345);
	// printf("real: %-15.5x|\n", 12345);
	// ft_printf("------------------------------------------------------------------------------\n");		
	// ft_printf("mine: %-10.*x|\n", 15, 12345);
	// printf("real: %-10.*x|\n", 15, 12345);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %23.12X|\n", 12345);
	// printf("real: %23.12X|\n", 12345);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %023.12x|\n", 12345);
	// printf("real: %023.12x|\n", 12345);
	// printf("---------------------------THESE ARE ALL CONFERSION OF U WITH FLAGS------------------\n");
	// ft_printf("mine: %u|\n", 429496729);
	// printf("real: %u|\n", 429496729);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %23.12u|\n", 429496729);
	// printf("real: %23.12u|\n", 429496729);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %.23u|\n", 429496729);
	// printf("real: %.23u|\n", 429496729);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %.*u|\n", 25, 429496729);
	// printf("real: %.*u|\n", 25, 429496729);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %-6.18u|\n", 429496729);
	// printf("real: %-6.18u|\n", 429496729);	
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %-15.5u|\n", 429496729);
	// printf("real: %-15.5u|\n", 429496729);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %-10.*u|\n", 15, 429496729);
	// printf("real: %-10.*u|\n", 15, 429496729);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %23.12u|\n", 429496729);
	// printf("real: %23.12u|\n", 429496729);
	// printf("----------------------------THESE ARE ALL CONFERSIONS OF P WITH FLAGS----------------\n");
	// ft_printf("mine: %p|\n", p);
	// printf("real: %p|\n", p);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %-23p|\n", p);
	// printf("real: %-23p|\n", p);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %-*p|\n", 23 , p);
	// printf("real: %-*p|\n", 23, p);
	// ft_printf("------------------------------------------------------------------------------\n");	
	// ft_printf("mine: %23p|\n", p);
	// printf("real: %23p|\n", p);
	// printf("---------------------------ONLY PERCENT SIGNS----------------------------------------\n");
	// ft_printf("mine: %.s|\n", "hello");
	// printf("real: %.s|\n", "hello");
	// ft_printf("mine: %10.5d|\n", -216);
	// printf("real: %10.5d|\n", -216);
	ft_printf("%x|\n", -8000);
	printf("%x|\n", -8000);
}
