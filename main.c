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
