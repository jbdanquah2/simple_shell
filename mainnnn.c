#include "main.h"

/**
 * main - Entry point.
 * @ac: arguments count.
 * @av: arguments.
 * @env: environment variables.
 *
 * Return: nothing.
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
		ptr = strtok(string, " \n");

		if ((strncmp("exit", ptr, 4) == 0))
			break;
		_strcat(cmd, ptr);
		if (stat(cmd, &st) == 0)
		{
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
