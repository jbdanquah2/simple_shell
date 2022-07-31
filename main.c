#include "main.h"

/**
 * main - Entry point
 *
 * Return: nothing
 *
 */
int main(void)
{
	int bytes_read;
	size_t size = 1;
	char *string;
	pid_t pid;

	pid = fork();
	type_prompt();
	if (pid != 0)
		wait(NULL);

	string = malloc(sizeof(char) * size);
	if (string == NULL)
	{
		perror("Error:");
		exit(1);
	}
	bytes_read = getline(&string, &size, stdin);
	while (bytes_read != -1)
	{
	/**	printf("%s", string); */
		type_prompt();
		bytes_read = getline(&string, &size, stdin);
	}

	return (0);
}
