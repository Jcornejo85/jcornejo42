/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:40:40 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/09 12:40:14 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*aux;
	size_t	cont;
	size_t	i;
	size_t	slen;

	cont = 0;
	i = start;
	if (!s)
		return (NULL);
	aux = (char *)malloc((len + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
	{
		aux[cont] = '\0';
		return (aux);
	}
	while (i < len + start)
	{
		aux[cont++] = s[i++];
	}
	aux[cont] = '\0';
	return (aux);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		cont;
	int		cont2;
	char	*dest;

	cont2 = 0;
	cont = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[cont])
	{
		dest[cont] = s1[cont];
		cont++;
	}
	while (s2[cont2])
	{
		dest[cont] = s2[cont2];
		cont++;
		cont2++;
	}
	dest[cont] = '\0';
	return (dest);
}

int		ft_strchr(char *s, char needle)
{
	int i;

	i = 0;
	if (!(s || needle))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == needle)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char		*dup;
	const char	*s2;
	int			len;
	int			i;

	len = 0;
	s2 = (char*)s1;
	while (s2[len] != '\0')
		len++;
	dup = (char*)malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s2[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
