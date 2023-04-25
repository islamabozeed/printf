#include "main.h"

/**
 * get_space - check main
 * @ar: arg
 * @li: the list
 *
 * Return: Alyawys 0
 */
int get_space(const char *ar, int *li)
{
	int curr_li = *li + 1;
	int space = 0;

	if (ar[curr_li] == 'l')
		space = LONG_SIZE;
	else if (ar[curr_li] == 'h')
		space = SHORT_SIZE;

	if (space == 0)
		*li = curr_li - 1;
	else
		*li = curr_li;

	return (space);
}
