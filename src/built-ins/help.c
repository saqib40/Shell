#include "../../include/everything.h"

// aka
// char **builtin_str
char *builtin_str[] = {
    "cd",
    "help",
    "exit",
    "pwd",
    "export",
    "unset"
};

int (*builtin_func[]) (char **) = {
    &shell_cd,
    &shell_help,
    &shell_exit,
    &shell_pwd,
    &export,
    &unset
};

int shell_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

int shell_help(char **args) {
    printf("Custom Shell\n");
    printf("Type program names and arguments, then press enter.\n");
    printf("The following built-in commands are available:\n");
    for (int i = 0; i < shell_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }
    return 1;
}