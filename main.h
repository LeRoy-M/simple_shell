#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/stdc++.h>
#include <readline/readline.h>
#include <readline/history.h>
int get_input(char *str);
void print_cwd(void);
int process_string(char *str, char **parsed, char **parsedpipe);
int parse_pipe(char *str, char **strpiped);
void parse_space(char *str, char **parsed);
int cmd_handler(char **parsed);
void exec_args(char **parsed);
void exec_piped_args(char **parsed, char **parsedpipe);

#define MAXLETR 1000 /* max number of letters to be supported */
#define MAXCOMD 100 /* max number of commands to be supported */

/* Clearing the shell using escape sequences */
#define clear() printf("\033[H\033[J")

#endif /* MAIN_H */
