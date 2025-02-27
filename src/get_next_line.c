/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrafzal <mrafzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:40:58 by mrafzal           #+#    #+#             */
/*   Updated: 2025/02/27 20:17:23 by mrafzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../resources/get_next_line.h"

char *get_next_line(int fd) {
    char buffer[BUFFER_SIZE + 1];
    static char *storage;
    int bytes_read;

    storage = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    while (!ft_strchr(storage, '\n')) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        storage = ft_strjoin(storage, buffer);
    }
    char *line = extract_line(storage);
    storage = save_remaining(storage);
    return line;
}

