#include "../include/everything.h"

int shell_launch(char **args) {
    pid_t pid, wpid;
    int status;
    pid = fork();
    if(pid < 0) {
        // fork failed
        perror("error just occured");
    }
    else if(pid == 0) {
        // child process
        // here we will run the command of the user
        if (execvp(args[0], args) == -1) {
            perror("error just occured");
        }
        exit(EXIT_FAILURE);
    }
    else {
        // parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return 1;
}

int shell_execute_process(char **args) {
    // still to do
    if (args[0] == NULL) {
        return 1;
    }
    for(int i=0; i < lsh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }
    // if not the builtin command
    // then
    // from /bin
    // can fail cause the tokenization isn't stong enough
    return lsh_launch(args);
}