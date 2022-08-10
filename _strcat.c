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
	int i, len1, len2;

	len1 = strlen(dest);
	len2 = strlen(src);
	for (i = 0; i <= len2; i++)
	{
		dest[len1 + i] = src[i];
	}
	return (ptr);
}
