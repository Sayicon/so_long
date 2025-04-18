/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 02:41:17 by mcekici           #+#    #+#             */
/*   Updated: 2024/11/05 02:45:38 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	print(const char *format, va_list *args, int *count)
{
	if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(*args, int), count);
	else if (*format == 'u')
		ft_put_un_nbr(va_arg(*args, unsigned int), count);
	else if (*format == 's')
		(*count) += ft_putstr((char *)va_arg(*args, int *));
	else if (*format == 'c')
		(*count) += ft_putchar((char)va_arg(*args, int));
	else if (*format == 'x')
		ft_putx_low(va_arg(*args, unsigned int), count);
	else if (*format == 'X')
		ft_putx_up(va_arg(*args, unsigned int), count);
	else if (*format == 'p')
		ft_putaddress(va_arg(*args, void *), count);
	else if (*format == '%')
		(*count) += ft_putchar('%');
}

int	ft_printf(const char	*format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			print(format, &args, &count);
			if (*format)
				format ++;
		}
		else
			count += ft_putchar(*(format++));
	}
	return (count);
}
