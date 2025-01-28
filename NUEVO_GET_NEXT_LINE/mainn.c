#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32
extern char	*get_next_line(int fd);

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	if (argc < 2)
	{
		write(1, "Usage: ./program file1.txt [file2.txt ...]\n", 42);
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			i++;
			continue;
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
		i++;
	}

	return (0);
}
