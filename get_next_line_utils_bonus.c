/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcornejo <jcornejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:40:40 by jcornejo          #+#    #+#             */
/*   Updated: 2019/12/14 11:37:22 by jcornejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*str;
	int		i;
	int		i2;

	i = -1;
	i2 = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		str[i2++] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		str[i2++] = s2[i];
	str[i2] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*space;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	space = (char*)malloc(len + 1);
	if (space == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		space[i] = s1[i];
		i++;
	}
	space[i] = '\0';
	return (space);
}

 char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*str;
	unsigned long int	i;
	unsigned int		str_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char*)malloc(len + 1)))
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
	{
		str[i] = '\0';
		return (str);
	}
	while (len > i)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	if (c == 0)
		return ("\0");
	return (NULL);
}