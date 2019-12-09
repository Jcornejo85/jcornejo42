#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE = 2;

int     ft_next_line(char *str, char **line)
{
    int i;
    int len;

    len = ft_strlen(str);
    i = 0;

    while (str[i] != '\n' && str[i] != '\0')
        i++;
    *line = ft_substr(str, 0, i);
    if (i != len)
    {
        *str = ft_substr(str, i, len - i);
        return (1);
    }
    else 
        return (0); 
}

int     get_next_line(int fd, char **line)
{
    static char *str[4096];
    char        buff[BUFF_SIZE + 1];
    char        *tmp;
    int         ret;

    if (fd < 0 || line == NULL)
        return (-1)
    while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
    {
        buff[ret] = '\0';
        if (str[fd] = NULL)
            str[fd] = ft_strdup(buff);
        else
        {
            tmp =  ft_strjoin(str,[fd] buff);
            free (str);
            str[fd] = tmp;
            free (tmp);
        }
        if (ft_strchr(str[fd], '\n'))
            break;
    }
    return (ft_next_line (str[fd], line))


}
tengo que crear una función que busque el salto de linea,+
lo guarde en line, y lo que sobre del salto de linea lo guarde
en str, para futuras nuevas lineas.