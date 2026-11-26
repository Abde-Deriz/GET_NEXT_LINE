/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askantar <askantar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:44:29 by askantar          #+#    #+#             */
/*   Updated: 2026/11/26 09:42:04 by askantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// 
// char *leftovers,
// saved = ft_strjoin ()

// saved = hello world  \n
// ft_strjoin -> keep track of what comes after \n 
// read multiple times till you find \n 
// once you find \n return the line and save the leftovers 
// in a static variable


// limit fd , hard limit , soft limit , diff btwn sh btween run place , usermode kernel mode , space, 
// change limit fd for every process stack limit change it

#include "get_next_line.h"
// still leak
static char *extract_line(char *leftover, int fd)
{
	char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;
	char *tmp;

	while (!leftover || !fn_line(leftover, '\n'))
    {
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(leftover, buffer);
		if (!tmp)
            return (free(leftover), leftover = NULL, NULL);
		free(leftover);
		leftover = tmp;
    }
	// check why not need !leftover || >> we need it if no left ex file.txt = 7 lines call gnl 10 times this guard for no left EOF
	if (!leftover || !*leftover)
		return (free(leftover), leftover = NULL, NULL);
	return (leftover);
}

static char *get_line(char **leftover)
{
	char *tmp;
	char *line;
	int i;
	int n;

	i = 0;
	// && fn_line(&(*leftover)[i], '\n')// fnl+len
	while ((*leftover)[i] && (*leftover)[i] != '\n')
		i++;
	if ((*leftover)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
        return (NULL);
	n = -1;
	while (++n < i)
		line[n] = (*leftover)[n];
	line[i] = '\0';

	if ((*leftover)[i] == '\0')
{
    free(*leftover);
    *leftover = NULL;
}
else 
{	tmp = ft_strjoin("", (*leftover + i));
	if (!tmp)
    	return (free(line), free(*leftover), *leftover = NULL, NULL);
	free(*leftover);
	*leftover = tmp;}
	return (line);
}

char *get_next_line(int fd)
{
	static char *leftover;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
    	return (NULL);
	leftover = extract_line(leftover , fd);
	if (!leftover) // this required 
		return (free(leftover), leftover = NULL, NULL);
	line = get_line(&leftover);
	if (!line) // this safe is only for handle return
		return (free(leftover), leftover = NULL, NULL);
	return (line);
}