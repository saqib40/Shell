#ifndef EVERYTHING_H
#define EVERYTHING_H
#define SHELL_BUFSIZE 1024
#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " \t\r\n\a"

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>

char **shell_parse_line(void) {

}

int shell_execute_process(char **args) {

}

char *shell_read_line(void) {

}

int shell_launch(char **args) {
    
}

// built-ins
int shell_cd (char **args) {

}

int shell_pwd (char **args) {

}

int export (char **args) {

}

int unset(char **args) {
    
}

int shell_help(char **args) {

}

int shell_exit(char **args) {

}

// some global variables
extern char *builtin_str[];
extern int (*builtin_func[]) (char **);
int shell_num_builtins();

#endif