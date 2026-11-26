/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: askantar <askantar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:52:15 by askantar          #+#    #+#             */
/*   Updated: 2026/11/25 18:52:18 by askantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

char *ft_strjoin(const char *s1, const char *s2);
int fn_line(char const *str, int c);
size_t ft_strlen(const char *s);
char *get_next_line(int fd);
