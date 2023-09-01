#include "main.h"
<<<<<<< HEAD

=======
>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca
/**
 * _atoi - convert a string into an integer.
 *
 * @s: the string to use.
 *
 * Return: integer.
 */
<<<<<<< HEAD

int _atoi(char *s)
{
	int sign = 1, i = 0;
	unsigned int res = 0;

	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	res *= sign;
	return (res);
}
=======
int _atoi(char *s)
{
 	int sign = 1, i = 0;
 	unsigned int res = 0;


 	while (!(s[i] <= '9' && s[i] >= '0') && s[i] != '\0')
 	{
 		if (s[i] == '-')
 			sign *= -1;
 		i++;
 	}
 	while (s[i] <= '9' && (s[i] >= '0' && s[i] != '\0'))
 	{
 		res = (res * 10) + (s[i] - '0');
 		i++;
 	}
 	res *= sign;
 	return (res);
 }
>>>>>>> ae1c4344bc22a5202085c87474ae6128c8968aca

