#include "../include/everything.h"

void shell_loop(void) {
    char *line;
    char **args;
    int status;
    do {
        printf(">");
        line = shell_read_line();
        args = shell_parse_line();
        status = shell_execute_process(args);
        free(line);
        free(args);
    } while(status);
}

int main() {

    // run the shell in loop
    shell_loop();

    return 0;

}