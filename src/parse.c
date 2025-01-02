#include "stdio.h"
#include "stdlib.h"
#define SHELL_TOK_BUFSIZE 64
#define SHELL_TOK_DELIM " \t\r\n\a"

char **shell_parse_line(char* line) {
    int bufsize = SHELL_TOK_BUFSIZE;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    if (!tokens) {
        fprintf(stderr, "lsh: allocation error\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, SHELL_TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        if (position >= bufsize) {
            bufsize += SHELL_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, SHELL_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}