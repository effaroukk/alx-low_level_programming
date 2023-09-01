#include "main.h"
<<<<<<< HEAD
#include <stddef.h>

=======
>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */
char *_strchr(char *s, char c)
{
	int i = 0;

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}

