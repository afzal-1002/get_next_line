/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafzal <mrafzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:46:24 by mrafzal           #+#    #+#             */
/*   Updated: 2025/02/27 20:17:31 by mrafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#define BUFFER_SIZE 40

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_file {
    char *storage;
    int fd;
} t_file;

char *strchr(const char *s, int c);
size_t ft_strlen(const char *s);
char *get_next_line(int fd);
char * ft_strjoin(const char *s1, const char *s2);
char *extract_line(char *storage);
char *ft_read_file(int fd, char *storage);

#endif