#ifndef MAIN_H
 #define MAIN_H

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdarg.h>
 #include <sys/types.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <string.h>
 #include <sys/stat.h>
 #include <errno.h>

 void type_prompt(void);
 char *_strcat(char *dest, char *src);
 void get_command(char *str, char **av);

 #endif
