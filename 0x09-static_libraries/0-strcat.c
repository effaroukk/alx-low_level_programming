#include "main.h"
<<<<<<< HEAD
/**
=======
 /**
>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
<<<<<<< HEAD
 * Return: void
=======
 * Return: void	
>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
<<<<<<< HEAD
	}
=======
	}		

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca

	dest[i] = '\0';
	return (dest);
}

