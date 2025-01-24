#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Abre el archivo prueba.txt
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Lee e imprime cada línea del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // Imprime la línea leída
        free(line);          // Libera la memoria de la línea
    }

    // Cierra el archivo
    close(fd);

    return 0;
}