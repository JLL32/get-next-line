/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hach <ael-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:49:57 by ael-hach          #+#    #+#             */
/*   Updated: 2020/01/30 16:38:07 by ael-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*buffer;
	static char	*text[255];
	int			ret;
	char		*temp;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		if (text[fd] == NULL)
			text[fd] = ft_strdup("");
		temp = ft_strjoin(text[fd], buffer);
		free(text[fd]);
		text[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (get_line(line, &(text[fd]), ret));
}

void	strremove(char **str)
{
	if (str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*s)
		s++;
	return (s - str);
}

char	*ft_strchr(const char *string, int c)
{
	size_t	n;

	n = ft_strlen(string) + 1;
	while (n--)
	{
		if (*string == c)
			return (char *)(string);
		string++;
	}
	return (0);
}

int		get_line(char **line, char **text, int ret)
{
	size_t	counter;
	char	*temp;

	if (*text != NULL)
	{
		if (ret > 0 || ft_strchr(*text, '\n'))
		{
			counter = 0;
			while ((*text)[counter] != '\n' && (*text)[counter])
				counter++;
			*line = ft_substr(*text, 0, counter);
			temp = ft_strdup(*text + counter + 1);
			free(*text);
			*text = temp;
			return (1);
		}
		*line = ft_strdup(*text);
		strremove(text);
	}
	else
		*line = ft_strdup("");
	return (ret < 0 ? -1 : 0);
}
