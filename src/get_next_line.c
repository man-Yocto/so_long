/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalkhaso <aalkhaso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 05:22:23 by aalkhaso          #+#    #+#             */
/*   Updated: 2025/08/18 10:40:03 by aalkhaso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

static char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;
	unsigned char	*str;

	str = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)&str[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

static char	*new_value(char *c)
{
	char	*copy;
	int		len;
	int		target;

	if (!c || !*c)
		return (NULL);
	target = 0;
	len = ft_strlen(c);
	while (c[target] != '\n')
	{
		target++;
		if (target == len)
			return (NULL);
	}
	if (target + 1 >= len)
		return (NULL);
	copy = ft_substr(c, target + 1, (len - target - 1));
	return (copy);
}

static char	*new_line(char *c)
{
	char	*s;
	int		len;
	char	*copy;
	int		target;

	target = 0;
	if (!c || !*c)
		return (NULL);
	len = ft_strlen(c);
	while (c[target] != '\n')
	{
		target++;
		if (target == len)
		{
			copy = ft_strdup(c);
			return (copy);
		}
	}
	if (c[target] == '\n')
		s = ft_substr(c, 0, target + 1);
	else
		s = ft_substr(c, 0, target);
	return (s);
}

static char	*fill_line(int fd, char *c, char *buffer)
{
	int		bytesrd;
	char	*tmp;

	bytesrd = 1;
	while ((c == NULL || !ft_strchr(c, '\n')) && bytesrd > 0)
	{
		bytesrd = read(fd, buffer, BUFFER_SIZE);
		if (bytesrd == -1)
		{
			free(c);
			return (NULL);
		}
		buffer[bytesrd] = '\0';
		if (!c)
			c = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(c, buffer);
			free(c);
			c = tmp;
		}
	}
	return (c);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	char		*tmp;
	static char	*c;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	c = fill_line(fd, c, buffer);
	free(buffer);
	if (!c || !*c)
	{
		free(c);
		c = NULL;
		return (NULL);
	}
	line = new_line(c);
	tmp = new_value(c);
	if (c)
		free(c);
	c = tmp;
	return (line);
}

