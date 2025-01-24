/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:02:24 by emilgarc          #+#    #+#             */
/*   Updated: 2025/01/23 12:02:11 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*printline(char *line) // esta función 
{
	int		i;		// indice normal y corriente
	char	*rem;	//donde voy a almacenar el resto de la cadena despues del salto de linea

	i = 0;	//	iniciamos el indice
	while (line[i] != '\n' && line[i] != '\0') //bucle para saltar la parte de la linea q si queremos imprimir
		i++;
	if (line[i] == 0 || line[i + 1] == 0) // para saber si na cadena a terminado buscamos el null sino sabremos que lo que hay es un salto de linea 
		return (NULL);
	rem = ft_substr(line, i + 1, ft_strlen(line) - i); //	almacenamos en rem lo que hay despues del salto de linea.
	if (*rem == 0)	//si rem esta vacio lo iguala a null
		rem = NULL;
	line[i + 1] = 0; // termina en null en donde estaría el salto de línea
	return (rem); //devuelve la linea q hay despues del salto.
}

char	*readline(int fd, char *buffer, char *rem) // esta función almacena en rem la linea completa hasta que he copiado un salto de líneo O la cadena ha terminado
{
	int			bytes_read;	// numero de bytes leidos
	char		*temp;		// temporal que me sirve para copiar y pegar

	bytes_read = 1;			// iniciamos bytes read en 1 para entrar al bucle
	while (bytes_read > 0)	// bucle bytes read mayor que uno por que cuando acabe no va a haber ninguno y sale. 
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);	
		/* almacenamos en bytesread el resultado de numeros leidos (lo que devuleve read) 
		y le decimos que lea fd, y almacene en el buffer el tamaño de biffersize */
		if (bytes_read == -1) // gestion de error en caso de que read falle devuelve eso
		{
			free(rem);
			return (NULL);					//puede que en este free este el error??????????????????????????????????????????????''
		}
		else if (bytes_read == 0) 	// si no lee nada es por que ha terminado o el fd esta vacío
			break ;					// así que nos salimos
		buffer[bytes_read] = 0;		//terminamos nuestro buffer en null
		if (!rem)					//si rem todavia no tiene nada
			rem = ft_strdup("");	//la inicializamos con una cadena vacía
		temp = rem;		// igualo tem a rem, para copiar lo que tenga en rem.
		rem = ft_strjoin(temp, buffer);		// en rem ccopio rem (temp) antes de lo que esta en el buffer para así ir completando la cadena
		free(temp);		// libero temp para la siguiente operación
		temp = NULL;	
		if (ft_strchr(rem, '\n'))	//busco si dentro de rem he copiado algun salto de linea y en ese caso me salgo del bucle.
			break ;
	}
	return (rem);		//devuelvo la cadena (cuando he copiado un salto de líneo O cuando la cadena ha terminado)
}

char	*get_next_line(int fd) //funcion principal
{
	char		*buffer;	//variable temporal que aloja el buffer size
	char		*line;		//donde voy almacenado la linea
	static char	*rem;		//una variable temporal estática que almacena el resto

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));	//alojamos memoria en buffer para el tamaño del buffersize 
	if (fd < 0 || BUFFER_SIZE <= 0)	// control de errores que devuelve Null y libera en caso de q falle fd o de que no haya buffersize
	{
		free(buffer);	//liberamos buffer ya q hemos alojado memoria previamente
		rem = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)		//control de errores de malloc
		return (NULL);
	line = readline(fd, buffer, rem);	//	llamada a la funcion readline con el fd, el buffer y el rem, almacenamos en line el resultado de rem
	free(buffer);	//liberamos el buffer puesto que ya tenemos la linea copiada de cara a la siguiente 
	if (!line)	//gestion de error si no hay linea.
		return (NULL);
	rem = printline(line); 		//mandamos la linea a printline que nos va a devolver el trozo que hay despues de el salto.
	return (line);		// devolvemos la linea
}

int main(void)
{
    int     fd;
    char    *line;

    // Abre el archivo prueba.txt en modo solo lectura
    fd = open("prueba.txt", O_RDONLY);
    if (fd == -1) // Verifica si hubo error al abrir el archivo
    {
        printf("Error al abrir el archivo");
        return (1);
    }

    // Lee y muestra las líneas del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linea: %s", line); // Imprime la línea leída
        free(line);  // Libera la memoria después de usarla
    }

    // Cierra el archivo
    close(fd);

    return (0);
}