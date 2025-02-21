#include "../../include/everything.h"

int shell_cd (char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "lsh: expected argument to \"cd\"\n");
    }
    else {
        if (chdir(args[1]) != 0) {
            fprintf(stderr, "Error changing directory: %s\n", strerror(errno));
        }
    }
    return 1;
}