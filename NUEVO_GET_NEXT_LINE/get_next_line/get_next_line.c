/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:12:48 by emilgarc          #+#    #+#             */
/*   Updated: 2025/01/24 15:06:45 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_alloc(int fd, char *str)
{
	char	*buffer;
	ssize_t	len;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	len = 1;
	while ((!ft_strchr(str, '\n')) && len > 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1)
		{
			free(buffer);
			free(str);
			buffer = NULL;
			return (0);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*nline(char *str)
{
	int		len;
	int		i;
	char	*new;

	i = 0;
	len = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	new = (char *)malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*rline(char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * ((len(line) - i) + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free (line);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free (str);
		str = NULL;
		return (NULL);
	}
	str = ft_alloc(fd, str);
	if (!str)
		return (NULL);
	line = nline(str);
	str = rline(str);
	return (line);
}
