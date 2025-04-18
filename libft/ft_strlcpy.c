/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:24:08 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:24:08 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!size)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (src[i] && i < (size - 1))
	{
		if (src[i] != '\r')
		{
			dest[i] = src[j];
			i ++;
			j ++;
		}
		else
			j ++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
