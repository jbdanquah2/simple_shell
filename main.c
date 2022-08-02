#include "main.h"

/**
 * main - Entry point
 *
 * Return: nothing
 *
 */

int main(int ac __attribute__((unused)), char *av[] __attribute__((unused)), char **env)
{
	size_t size = 1;
	char *string, *ptr, *argv[256];
	struct stat st;
	pid_t pid;

	while (1)
	{
		char cmd[16] = "/bin/";
	
		type_prompt();

		string = malloc(sizeof(char) * size);
		if (string == NULL)
		{
			perror("Error:");
			exit(1);
		}

		getline(&string, &size, stdin);
		ptr = strtok(string, " ");

		_strcat(cmd, ptr);		
		if (stat(cmd, &st) == 0)
		{
			get_command(string, argv);	
			pid = fork();
			if (pid == -1)
			{
				perror("Error:");	
			}
			else if (pid == 0)
			{
				execve(cmd, argv, env);
			}
			else
			{
				waitpid(pid, NULL, 0);
			}
		}
		else
		{
			perror("Error:");
		}
	}

	return (0);
}

void get_command(char *str, char **av)
{
	char *p;
	int i = 0;

	p = strtok(str, " ");
	while (p != NULL)
	{
		av[i] = p;
		i++;
		p = strtok(NULL, " ");
	}
	av[i] = NULL;
}

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
