/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askantar <askantar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:52:10 by askantar          #+#    #+#             */
/*   Updated: 2026/11/25 18:52:06 by askantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int fn_line(char const *str, int c)
{
    while (*str)
    {
        if (*str == (char)c)
            return (1);
        str++;
    }
    return (0);
}

size_t ft_strlen(const char *s)
{
	size_t len;
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}
char *ft_strjoin(const char *s1, const char *s2)
{
	if (!s1)
    	s1 = "";
	if (!s2)
		s2 = "";
	int i , j;
	int s1len = ft_strlen(s1);
	int s2len = ft_strlen(s2);	
	char *newstr = malloc (s1len + s2len + 1);
	if(!newstr) return (NULL);

	i = 0;
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (newstr);
}
