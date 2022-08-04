#include "main.h"

/**
 * main - Entry point
 * @ac: arguments count
 * @av: arguments
 * @env: environment variables
 *
 * Return: nothing
 */

int main(int ac, char *av[], char **env)
{
	size_t size = 1;
	char *string, *ptr, *argv[12];
	struct stat st;
	pid_t pid;
	int j = 0, bytes_read;

	while (1)
	{
		char cmd[16] = "/bin/";

		type_prompt(); /* prints $ at the prompt */
		if (ac > 1)
			printf("%s\n", av[j]);

		string = malloc(sizeof(char) * size);
		if (string == NULL)
		{
			perror("Error:");
			exit(1);
		}
		bytes_read = getline(&string, &size, stdin);
		if (bytes_read == -1)
		{
			perror("Error:");
		}

		ptr = strtok(string, " ");

		if ((strncmp("exit", ptr, 4) == 0))
			break;
		_strcat(cmd, ptr);

		if (stat(cmd, &st) == 0)
		{
			if ((strlen(string) > 0) && (string[strlen (string) - 1] == '\n'))
        			string[strlen (string) - 1] = '\0';
			get_command(string, argv);
			argv[0] = cmd;

			pid = fork();
			if (pid == -1)
				perror("Error:");
			else if (pid == 0)
				execve(argv[0], argv, env);
			else
				waitpid(pid, NULL, 0);
		}
		else
			perror("./hsh");

		free(string); /* free the memory */
	}
	return (0);
}

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

	p = strtok(str, " "); /* splits the string */
	while (p != NULL)
	{
		if (strcmp(p, "\n"))
			break;
		av[i] = p;
		i++;
		p = strtok(NULL, " ");
	}
	av[i] = NULL; /* terminates with NULL */
}

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
