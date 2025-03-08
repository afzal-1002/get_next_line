/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:51:40 by mafzal            #+#    #+#             */
/*   Updated: 2025/03/08 18:29:51 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char *storage)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!storage || storage[i] == '\0')
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(i + 2);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = storage[j];
		j++;
	}
	if (storage[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*save_remaining(char *storage)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		return ((free(storage)), NULL);
	i++;
	str = (char *)malloc(ft_strlen(storage) - i + 1);
	if (!str)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i])
		str[j++] = storage[i++];
	str[j] = '\0';
	free(storage);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*storage[MAX_FD];
	int			bytes_read;
	char		*line;
	char		*buffer;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!storage[fd] || !ft_strchr(storage[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		storage[fd] = update_storage(storage[fd], buffer, bytes_read);
		if (!storage[fd])
			return (free(buffer), NULL);
	}
	free(buffer);
	line = extract_line(storage[fd]);
	if (!line)
		return (free(storage[fd]), storage[fd] = NULL, NULL);
	storage[fd] = save_remaining(storage[fd]);
	return (line);
}

char	*update_storage(char *storage, char *buffer, int bytes_read)
{
	buffer[bytes_read] = '\0';
	if (!storage)
		storage = ft_strdup("");
	storage = ft_strjoin(storage, buffer);
	return (storage);
}
