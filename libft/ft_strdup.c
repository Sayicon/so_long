/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:23:52 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:23:52 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	len;

	len = ft_strlen(src);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, src, len + 1);
	return (ptr);
}
