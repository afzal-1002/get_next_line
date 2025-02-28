#include "includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h> // For read()

// Declare get_next_line and other helper functions
char	*get_next_line(int fd);
char	*extract_line(char *storage);
char	*save_remaining(char *storage);

int	main(void)
{
	int		fd;
	char	*line;

	// Open the test file
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open file");
		return (1);
	}
	// Read lines from the file using get_next_line
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("Line: %s", line);
	// 	free(line); // Don't forget to free the memory returned by get_next_line
	// }
	line = get_next_line(fd);
	printf("Line: %s", line);
	free(line); // Don't forget to free the memory returned by get_next_line
	// Close the file
	close(fd);
	return (0);
}
