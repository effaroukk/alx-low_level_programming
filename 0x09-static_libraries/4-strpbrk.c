#include "main.h"
/**
 * _strpbrk - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */
char *_strpbrk(char *s, char *accept)
{
	int k;

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
	while (*s)
	{
		for (k = 0; accept[k]; k++)
		{
		if (*s == accept[k])
		return (s);
		}
	s++;
	}

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
return ('\0');
}

