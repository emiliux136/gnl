/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:21:13 by emilgarc          #+#    #+#             */
/*   Updated: 2025/01/24 15:05:51 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[len(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*end;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	if (!str2)
		return (NULL);
	end = (char *)malloc(sizeof(char) * (len(str1) + len(str2) + 1));
	if (end == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		end[j++] = str1[i++];
	i = 0;
	while (str2[i])
		end[j++] = str2[i++];
	end[j] = '\0';
	free(str1);
	return (end);
}

size_t	len(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
