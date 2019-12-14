/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <jcornejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:11 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/14 11:30:45 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//#define BUFFER_SIZE 33
#define MAX_FD 4096

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int		ft_strlen(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int get_next_line(int fd, char **line);

#endif