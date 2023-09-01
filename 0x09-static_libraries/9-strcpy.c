#include "main.h"
<<<<<<< HEAD

=======
		
>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}

