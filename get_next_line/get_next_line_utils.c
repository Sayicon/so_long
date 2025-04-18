/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:02:40 by mcekici           #+#    #+#             */
/*   Updated: 2024/12/24 13:02:40 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
	{
		str1 = (char *)malloc(1);
		*str1 = '\0';
	}
	result = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (result == 0)
		return (0);
	while (str1[i])
		result[j++] = str1[i++];
	i = 0;
	while (str2[i])
		result[j++] = str2[i++];
	result[j] = '\0';
	free(str1);
	return (result);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
