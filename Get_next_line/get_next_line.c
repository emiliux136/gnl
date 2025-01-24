/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:02:24 by emilgarc          #+#    #+#             */
/*   Updated: 2025/01/23 16:21:06 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*allocrest(char *line)
{
	ssize_t		i;
	char		*rest;

	i = 0;
	
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[i + 1] == 0)
		return (NULL);
	rest = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	line[i + 1] = 0;
	return (rest);
}

char	*readline(int fd, char *buffer, char *rem)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(rem);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!rem)
			rem = ft_strdup("");
		temp = rem;
		rem = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(rem, '\n'))
			break ;
	}
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*rem;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rem);
		free(buffer);
		rem = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = readline(fd, buffer, rem);
	free(buffer);
	if (!line)
		return (NULL);
	rem = allocrest(line);
	return (line);
}
