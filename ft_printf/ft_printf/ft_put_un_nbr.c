/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_un_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:28 by mcekici           #+#    #+#             */
/*   Updated: 2024/12/26 12:42:00 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_un_nbr(unsigned int un, int *sum)
{
	if (!(un <= 9))
	{
		ft_put_un_nbr(un / 10, sum);
		(*sum) += ft_putchar(un % 10 + '0');
	}
	else
		(*sum) += ft_putchar(un + '0');
}
