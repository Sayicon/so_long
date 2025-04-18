/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:48 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/05 02:41:51 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *sum)
{
	if (n == -2147483648)
		(*sum) += ft_putstr("-2147483648");
	else if (n < 0)
	{
		(*sum) += ft_putchar('-');
		ft_putnbr(-n, sum);
	}
	else if (!(n <= 9 && n >= 0))
	{
		ft_putnbr(n / 10, sum);
		(*sum) += ft_putchar(n % 10 + '0');
	}
	else
		(*sum) += ft_putchar(n + '0');
}
