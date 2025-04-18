/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:36 by mcekici           #+#    #+#             */
/*   Updated: 2024/12/26 12:58:22 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive_printaddress(unsigned long adr, int *sum)
{
	if (!adr)
		return ;
	else
	{
		recursive_printaddress(adr / 16, sum);
		if ((adr % 16) < 10)
			(*sum) += ft_putchar('0' + (adr % 16));
		else
			(*sum) += ft_putchar('a' + (adr % 16) - 10);
	}
}

void	ft_putaddress(void *address, int *sum)
{
	if (address == (void *)0)
	{
		(*sum) += ft_putstr("(nil)");
		return ;
	}
	(*sum) += ft_putstr("0x");
	if (!address)
		(*sum) += ft_putchar('0');
	recursive_printaddress((unsigned long)address, sum);
}
