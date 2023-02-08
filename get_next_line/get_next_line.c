/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:49:42 by jrouillo          #+#    #+#             */
/*   Updated: 2022/12/08 12:10:44 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*line;

	i = 0;
	j = 0;
	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (j < len)
		line[j++] = str[i++];
	line[j] = '\0';
	return (line);
}

char	*get_rest(char *str)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	j = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!rest)
		return (NULL);
	i += (str[i] == '\n');
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*get_str(int fd, char *str)
{
	ssize_t	nbyte;
	char	*buf;

	nbyte = 1;
	buf = malloc((BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (!str)
		str = ft_calloc(1, 1);
	while (nbyte > 0 && !ft_strchr(str, '\n'))
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte <= 0)
		{
			free(buf);
			if (str[0] != '\0')
				return (str);
			free(str);
			return (NULL);
		}
		buf[nbyte] = '\0';
		str = ft_free_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = get_str(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_rest(str);
	return (line);
}
