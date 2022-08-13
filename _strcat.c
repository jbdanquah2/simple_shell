#include "main.h"

/**
 * _strcat - concats a source string to a destination string
 * @dest: destination string
 * @src: source string
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;
	int x, len1, len2;

	len1 = strlen(dest);
	len2 = strlen(src);
	for (x = 0; x <= len2; x++)
	{
		dest[len1 + x] = src[x];
	}
	return (ptr);
}
