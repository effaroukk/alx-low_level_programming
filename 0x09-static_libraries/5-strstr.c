#include "main.h"
/**
 * _strstr - Entry point
 * @haystack: input
 * @needle: input
 * Return: Always 0 (Success)
 */
char *_strstr(char *haystack, char *needle)
{
	for (; *haystack != '\0'; haystack++)
	{
		char *l = haystack;
		char *p = needle;

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
		while (*l == *p && *p != '\0')
		{
			l++;
			p++;
		}

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
		if (*p == '\0')
			return (haystack);
	}

<<<<<<< HEAD
=======

>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
	return (0);
}

