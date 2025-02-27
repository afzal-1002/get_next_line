/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafzal <mrafzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:44:16 by mrafzal           #+#    #+#             */
/*   Updated: 2025/02/27 20:18:37 by mrafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

char *extract_line(char *storage) {
    char *line;
    int i = 0;

    while (storage[i] && storage[i] != '\n') 
        i++;
    line = (char *)malloc(i+2);
    if (!line) return NULL;
    
    int j = 0;
    while (j < i) {
        line[j] = storage[j];
        j++;
    }
    if (storage[i] == '\n') line[j++] = '\n';
    line[j] = '\0';
    return line;
}


char *ft_read_file(int fd, char *storage) {
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;

    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0) return storage;

    buffer[bytes_read] = '\0';
    return ft_strjoin(storage, buffer);
}

char *save_remaining(char *storage) {
    char *remaining;
    int i = 0;

    while (storage[i] && storage[i] != '\n') 
        i++;

    if (!storage[i]) {
        free(storage);
        return NULL; 
    }

    remaining = malloc(ft_strlen(storage) - i);
    if (!remaining) return NULL;

    int j = 0;
    while (storage[++i]) {
        remaining[j++] = storage[i];
    }
    remaining[j] = '\0';

    free(storage);
    return (remaining);
}
