/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:23:14 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:23:14 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!src && !dst)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n > 0)
	{
		*(d++) = *(s++);
		n --;
	}
	return (dst);
}
