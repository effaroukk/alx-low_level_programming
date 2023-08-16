#include "main.h"
/**
 * _abs - Computes the absolute value of an integer
 * @y: The number to be checked
 * Return: Absolute value of number or zero
 */
int _abs(int y)
{
	if (y < 0)
	{
		int abs_val;

		abs_val = y * -1;
		return (abs_val);
	}
	return (y);
}
