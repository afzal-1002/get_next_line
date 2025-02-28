/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:07:49 by mafzal            #+#    #+#             */
/*   Updated: 2025/02/28 16:44:42 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

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
	if (storage[i] == '\n')
		line = (char *)malloc(i + 2);
	else
		line = (char *)malloc(i + 1);
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
	{
		free(storage);
		return (NULL);
	}
	i++;
	str = (char *)malloc(ft_strlen(storage) - i + 1);
	if (!str)
		return (NULL);
	while (storage[i])
		str[j++] = storage[i++];
	str[j] = '\0';
	free(storage);
	return (str);
}
