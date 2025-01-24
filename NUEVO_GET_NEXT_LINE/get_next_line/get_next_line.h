/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:02:27 by emilgarc          #+#    #+#             */
/*   Updated: 2025/01/24 15:06:01 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdio.h> 

char	*get_next_line(int fd);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *s, int c);
size_t	len(char *s);
char	*ft_alloc(int fd, char *str);
char	*rline(char *line);
char	*nline(char *str);

#endif