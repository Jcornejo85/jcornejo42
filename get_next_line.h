/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:49:11 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/09 17:11:08 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int     get_next_line(int fd, char **line);
int     ft_next_line(char **str, char **line);
int		ft_strlen(char *s);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strchr(char *s, char needle);
char	*ft_strdup(char *s1);

#endif
