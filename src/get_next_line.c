/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 22:51:38 by mafzal            #+#    #+#             */
/*   Updated: 2025/02/28 20:55:44 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

// char	*ft_read_file(int fd, char *storage)
// {
// 	char	*buffer;
// 	int		byte_read;

// 	if (!storage)
// 		storage = ft_calloc(1, 1);
// 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	byte_read = 1;
// 	while (byte_read > 0)
// 	{
// 		byte_read = read(fd, buffer, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		buffer[byte_read] = 0;
// 		storage = ft_strjoin(storage, buffer);
// 		if (!storage)
// 			return (NULL);
// 		if (ft_strchr(buffer, '\n'))
// 			break ;
// 	}
// 	free(buffer);
// 	return (storage);
// }

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	buffer[bytes_read] = '\0';
	if (storage == NULL)
		storage = ft_strdup("");
	storage = ft_strjoin(storage, buffer);
	line = extract_line(storage);
	storage = save_remaining(storage);
	return (line);
}
