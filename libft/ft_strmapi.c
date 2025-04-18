/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:24:17 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:24:17 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		i ++;
	}
	new[i] = 0;
	return (new);
}
