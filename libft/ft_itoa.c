/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:22:00 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:22:00 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	numcount(int n)
{
	if (!(n / 10))
		return (1);
	else
		return (1 + numcount(n / 10));
}

static char	*convert(int n, char *ptr, int size)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
		i = 1;
	}
	ptr[--size] = 0;
	while (size > i)
	{
		ptr[--size] = (n % 10) + '0';
		n /= 10;
	}
	if (size == 1 && ptr[0] != '-')
		ptr[0] = (n % 10) + '0';
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = numcount(n) + 1;
	if (n < 0)
		size ++;
	ptr = (char *)malloc(size);
	if (!ptr)
		return (0);
	return (convert(n, ptr, size));
}
