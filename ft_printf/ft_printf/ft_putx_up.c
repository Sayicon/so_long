/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:42:10 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/05 02:46:37 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rec_print(unsigned int hex, int *sum)
{
	if (!hex)
		return ;
	else
	{
		ft_rec_print(hex / 16, sum);
		if ((hex % 16) < 10)
			(*sum) += ft_putchar('0' + (hex % 16));
		else
			(*sum) += ft_putchar('A' + (hex % 16) - 10);
	}
}

void	ft_putx_up(unsigned int hex, int *sum)
{
	if (hex == 0)
	{
		(*sum) += ft_putchar('0');
		return ;
	}
	ft_rec_print(hex, sum);
}
