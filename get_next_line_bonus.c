/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <jcornejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 12:13:49 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/14 11:38:00 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int ft_new_line(char **line, char **aux)
{
	int len;
	char *temp;

	len = 0;
	/*if(!*aux)
	{
		*line = ft_strdup(*aux);
		return(0);
	}*/
	//printf("%s\n", aux[len]);
	while ((*aux)[len] != '\0' && (*aux)[len] != '\n')
		len++;
	//printf("%d\n", len);
	if ((*aux)[len] == '\n')
	{
		*line = ft_substr(*aux, 0, len);
		//printf("A%s\n", *aux);
		temp = ft_strdup(&((*aux)[len + 1]));
		free(*aux);
		//printf("T%s\n", temp);
		*aux = temp;
	}
	else
	{
		//printf("PRUEBA");
		*line = ft_strdup(*aux);
		//free(*aux);
		return (0);
		//printf("%s\n P", *line);
	}
	return (1);
}

int ft_return_value(int len, char **line, char **aux)
{
	if (len < 0)
		return (-1);
	//else if (len == 0)
	//	return (0);
	else
		return (ft_new_line(line, aux));
}

int get_next_line(int fd, char **line)
{
	static char *aux[MAX_FD];
	char buff[BUFFER_SIZE + 1];
	char *temp;
	int len;

	if(fd < 0 || line == NULL)
		return (-1);
	while ((len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[len] = '\0';
		//printf("%s\n", buff);
		if (!aux[fd])
		{
			aux[fd] = ft_strdup(buff); //Copia del buffer leido
			//printf("B%s\n", aux[fd]);
		}
		else
		{
			temp = ft_strjoin(aux[fd], buff);
			free(aux[fd]);
			aux[fd] = temp;
			//printf ("%s\n", aux[fd]);
			//free(temp);
		}
		if (ft_strchr(aux[fd], '\n'))
			break;
	}
	if(len == 0 && aux[fd] == NULL)
		return (0);
	return (ft_return_value(len, line, &aux[fd]));
}