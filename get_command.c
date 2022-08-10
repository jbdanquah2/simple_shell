#include "main.h"

/**
 * get_command - Retrieves the commnad list from the shell
 * @str: pointer to the commands pass by the user
 * @av: pointer to the argv
 *
 * Return: nothing
 */
void get_command(char *str, char **av)
{
	char *p;
	int i = 0;

	p = strtok(str, " \n"); /* splits the string */
	while (p != NULL)
	{
		if (strcmp(p, "\n"))
			break;
		av[i] = p;
		i++;
		p = strtok(NULL, " \n");
	}
	av[i] = NULL; /* terminates with NULL */
}
