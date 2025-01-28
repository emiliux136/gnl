#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int	fd;
	int fdos;
	char *linea;

	fd = open("test.txt", O_RDONLY);
	fdos = open("test2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error de apertura");
		return (1);
	}
	printf("el fd es: %i \n", fd);
	while ((linea = get_next_line(fd)) != NULL)
	{
		printf("%s", linea);
		free (linea);
	}
	while ((linea = get_next_line(fdos)) != NULL)
	{
		printf("%s", linea);
		free (linea);
	}
	close(fd);
	return(0);
}