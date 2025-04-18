/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:54 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/05 02:57:17 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	counter;

	if (!str)
		return (ft_putstr("(null)"));
	counter = 0;
	while (*str)
		counter += ft_putchar(*(str++));
	return (counter);
}
