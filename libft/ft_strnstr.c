/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:24:25 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:24:25 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	i = ft_strlen(needle);
	while (*haystack && len && (len >= i))
	{
		if (!ft_strncmp(haystack, needle, i))
			return ((char *)haystack);
		haystack ++;
		len --;
	}
	return (NULL);
}
