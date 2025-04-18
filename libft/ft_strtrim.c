/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:24:31 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:24:31 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	startind;
	size_t	endind;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	startind = 0;
	while (s1[startind] && ft_strchr(set, s1[startind]))
		startind ++;
	endind = ft_strlen(s1) - 1;
	while (s1[endind] && ft_strchr(set, s1[endind]))
		endind --;
	return (ft_substr(s1, startind, endind - startind + 1));
}
