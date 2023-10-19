#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char** environ;

void print_environ() {
	char** env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

int env_remove_key(const char* key)
{
	int i;

    for (i = 0; environ[i] != NULL; i++) {
        char* var = environ[i];
        if (strstr(var, key) == var) {
            while (environ[i] != NULL) {
                environ[i] = environ[i + 1];
                i++;
            }
            return 0;
        }
    }
    return -1;
}
