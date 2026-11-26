#include "get_next_line.h"



char *get_line(char **leftover)
{
    char *line;
    char *tmp;
    int i = 0;
    int n = 0;

    while ((*leftover)[i] && (*leftover)[i] != '\n')
        i++;

    if ((*leftover)[i] == '\n')
        i++;

    line = malloc(i + 1);
    if (!line)
        return (NULL);

    while (n < i)
    {
        line[n] = (*leftover)[n];
        n++;
    }
    line[i] = '\0';

    tmp = strjoin("", (*leftover + i));
    if (!tmp)
        return (free(line), NULL);

    free(*leftover);
    *leftover = tmp;

    return (line);
}

char *get_next_line2(int fd)
{
    static char *leftover;
    char *tmp;
    char *line;
    int i;
    int n;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    leftover = extract_line(leftover, fd);
    if (!leftover)
        return (NULL);

    i = 0;
    while (leftover[i] && leftover[i] != '\n')
        i++;
    if (leftover[i] == '\n')
        i++;

    line = malloc(i + 1);
    if (!line)
        return (free(leftover), leftover = NULL, NULL);

    n = -1;
    while (++n < i)
        line[n] = leftover[n];
    line[n] = '\0';

    tmp = strjoin("", leftover + i);
    if (!tmp)
        return (free(line), free(leftover), leftover = NULL, NULL);

    free(leftover);
    leftover = tmp;

    return (line);
}

char *get_next_linev1(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    static char *leftover;
    ssize_t bytes_read;
    char *tmp;
    char *line;
    int i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    while (!leftover || !strchr(leftover, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;

        buffer[bytes_read] = '\0';
        tmp = strjoin(leftover, buffer);
        if (!tmp)
            return (free(leftover), leftover = NULL, NULL);

        free(leftover);
        leftover = tmp;
    }

    if (!leftover || !*leftover)
        return (free(leftover), leftover = NULL, NULL);

    i = 0;
    while (leftover[i] && leftover[i] != '\n')
        i++;

    if (leftover[i] == '\n')
        i++;

    line = malloc(i + 1);
    if (!line)
        return (free(leftover), leftover = NULL, NULL);

    memcpy(line, leftover, i);
    line[i] = '\0';

    tmp = strjoin("", leftover + i);
    if (!tmp)
        return (free(line), free(leftover), leftover = NULL, NULL);

    free(leftover);
    leftover = tmp;

    return (line);
}
