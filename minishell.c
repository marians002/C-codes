#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Split by spaces
char **split_whitespaces(char *buf)
{
    char **argv = malloc(100 * sizeof(char *));
    char *part = strtok(buf, " \n");
    int i = 0;
    while (part != NULL)
    {
        argv[i++] = part;
        part = strtok(NULL, " \n");
    }
    argv[i] = NULL;
    return argv;
}

int main()
{
    char buf[1000];
    char *line;
    while (1)
    {
        printf("$");
        line = fgets(buf, 1000, stdin);
        char **argv = split_whitespaces(line);

        if (strcmp(argv[0], "exit") == 0)
            exit(0);

        int rc = fork();
        
        if (rc > 0)
        {
            wait(NULL);
        }
        else if (rc == 0)
        {
            execvp(argv[0], argv);
        }
        else
        {
            printf("Esto no pincha");
        }

        free(argv);
    }

    return 0;
}
