#include "main.h"
/**
* _isupper - checks for uppercase character
* @d: Variable text
* Return: Always 0.
*/
int _isupper(int d)
{
	if (d >= 'A' && d <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

