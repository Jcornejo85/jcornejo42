/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <jcornejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:13:49 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/11 19:44:29 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_next_line(char **str, char **line)
{
	int		len;
	char	*aux;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		aux = ft_strdup(&((*str)[len + 1]));
		free(*str);
		*str = aux;
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	return (1);
}

int		ft_noline(int ret, char **str, char **line)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && *str == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else 
		return (ft_next_line(str, line));
}

int		get_next_line(int fd, char **line)
{
	static char		*str[4096];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = ft_strdup(tmp);
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	return (ft_noline(ret, &str[fd], line));
}
