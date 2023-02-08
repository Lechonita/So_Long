/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:49:46 by jrouillo          #+#    #+#             */
/*   Updated: 2022/12/08 12:10:45 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	char	*s;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (str)
	{
		s = str;
		while (*s1 && len1--)
			*s++ = *s1++;
		while (*s2 && len2--)
			*s++ = *s2++;
		*s = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	tmp;

	if (nmemb != 0 && size > ((SIZE_MAX) - 1) / nmemb)
		return (NULL);
	ptr = malloc(sizeof(void) * (nmemb * size));
	if (!ptr)
		return (NULL);
	tmp = nmemb * size;
	while (tmp--)
		((unsigned char *)ptr)[tmp] = '\0';
	return (ptr);
}
