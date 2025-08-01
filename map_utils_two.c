/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcekici <mcekici@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 13:46:04 by mcekici           #+#    #+#             */
/*   Updated: 2025/04/19 13:46:04 by mcekici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line/get_next_line_bonus.h"
#include "so_long.h"
#include <unistd.h>

static int		open_file(char *path);
static size_t	ft_strlen_modified(const char *s);
static void		copy_without_cr(char *dest, const char *src, size_t len1);
static char		*ft_strjoin_modified(char *s1, char *s2);

char	*get_map(char *path)
{
	int		fd;
	char	*map_buffer;
	char	*line;
	char	*temp;
	int		err_flag;

	fd = open_file(path);
	temp = 0;
	err_flag = 0;
	map_buffer = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen_modified(line) < 3)
			err_flag = 1;
		map_buffer = ft_strjoin_modified(temp, line);
		if (!map_buffer)
			handle_error("Error\nMemory allocation failed.\n", 1, 0);
		temp = map_buffer;
	}
	check_err(err_flag, fd, map_buffer);
	return (map_buffer);
}

static int	open_file(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFailed to open file.\n", 2);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static size_t	ft_strlen_modified(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != 0)
	{
		if (*s != '\r')
			len ++;
		s ++;
	}
	return (len);
}

static void	copy_without_cr(char *dest, const char *src, size_t len1)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != '\r')
			dest[len1 + j++] = src[i];
		i++;
	}
	dest[len1 + j] = '\0';
}

static char	*ft_strjoin_modified(char *s1, char *s2)
{
	char	*ptr;
	size_t	len1;
	size_t	len2;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	len2 = ft_strlen_modified(s2);
	ptr = (char *)ft_calloc(1, len1 + len2 + 1);
	if (!ptr)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	if (s1)
		ft_strlcpy(ptr, s1, len1 + 1);
	if (s2)
		copy_without_cr(ptr, s2, len1);
	free(s1);
	free(s2);
	return (ptr);
}
