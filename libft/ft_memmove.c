/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:23:18 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:23:18 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	if (!dst && !src)
		return (0);
	if (dst < src)
		return (ft_memcpy(dst, src, n));
	d = (char *)dst;
	s = (char *)src;
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n --;
	}
	return (dst);
}
