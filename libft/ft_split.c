/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:23:44 by mcekici           #+#    #+#             */
/*   Updated: 2024/10/16 14:23:44 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	wordcounter(char const *s, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i ++;
		if (s[i] && s[i] != sep)
			count ++;
		while (s[i] && s[i] != sep)
			i ++;
	}
	return (count);
}

static int	wordlen(char const *s, char sep)
{
	int	len;

	len = 0;
	while (s[len] != sep && s[len] && s[len] != '\r')
		len ++;
	return (len);
}

static int	ft_free(char **ptr, int i)
{
	while (i > 0)
		free(ptr[--i]);
	free(ptr);
	return (0);
}

char	**ft_split(char const *s, char sep)
{
	char	**splited;
	int		i;

	if (!s)
		return (0);
	splited = (char **)ft_calloc(wordcounter(s, sep) + 1, sizeof(char *));
	if (!splited)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == sep || *s == '\r')
			s ++;
		if (*s && *s != sep && *s != '\r')
		{
			splited[i] = ft_substr(s, 0, wordlen(s, sep));
			if (!(splited[i]))
				if (!ft_free(splited, i))
					return (0);
			s += wordlen(s, sep);
			i ++;
		}
	}
	splited[i] = 0;
	return (splited);
}
