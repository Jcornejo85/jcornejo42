/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <jcornejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:13:49 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/14 11:28:53 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_new_line(char **line, char **aux)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*aux)[len] != '\0' && (*aux)[len] != '\n')
		len++;
	if ((*aux)[len] == '\n')
	{
		*line = ft_substr(*aux, 0, len);
		temp = ft_strdup(&((*aux)[len + 1]));
		free(*aux);
		*aux = temp;
	}
	else
	{
		*line = ft_strdup(*aux);
		free(*aux);
		*aux = NULL;
		return (0);
	}
	return (1);
}

int	ft_return_value(int len, char **line, char **aux)
{
	if (len < 0)
		return (-1);
	else if (len == 0 && *aux == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_new_line(line, aux));
}

int	get_next_line(int fd, char **line)
{
	static char	*aux[MAX_FD];
	char		buff[BUFFER_SIZE + 1];
	char		*temp;
	int			len;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[len] = '\0';
		if (!aux[fd])
			aux[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(aux[fd], buff);
			free(aux[fd]);
			aux[fd] = temp;
		}
		if (ft_strchr(aux[fd], '\n'))
			break ;
	}
	return (ft_return_value(len, line, &aux[fd]));
}