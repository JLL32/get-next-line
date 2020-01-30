/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hach <ael-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:50:01 by ael-hach          #+#    #+#             */
/*   Updated: 2020/01/25 16:52:55 by ael-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	int			n;

	d = dst;
	s = src;
	n = size;
	if (n)
		while (--n)
			if (!(*d++ = *s++))
				break ;
	if (!n)
	{
		if (size)
			*d = '\0';
		while (*s++)
			;
	}
	return (s - src - 1);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	s = src;
	d = dst;
	n = size;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

char		*ft_strdup(const char *src)
{
	char	*dst;
	size_t	size;

	size = ft_strlen(src) + 1;
	if (!(dst = malloc(size)))
		return (0);
	ft_strlcpy(dst, src, size);
	return (dst);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(result = malloc(size)))
		return (NULL);
	ft_strlcpy(result, s1, size);
	ft_strlcat(result, s2, size);
	return (result);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	char	*startstr;
	size_t	size;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	size = sizeof(char) * len + 1;
	if (!(result = malloc(size)))
		return (NULL);
	startstr = (char *)s + start;
	ft_strlcpy(result, startstr, size);
	return (result);
}
