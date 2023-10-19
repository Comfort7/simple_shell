#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 512


char* env_vars[] = {
    "VAR1=value1",
    "VAR2=value2",

    NULL
};

const char* env_get_key(const char* key)
{
	int i;

    for (i = 0; env_vars[i] != NULL; i++) {
        char* token = strtok(env_vars[i], "=");
        if (token != NULL && strcmp(token, key) == 0) {
            char* value = strtok(NULL, "=");
            return value;
        }
    }
    return NULL;
}

int env_set_key(const char* key, const char* value)
{
	int i;

    for (i = 0; env_vars[i] != NULL; i++) {
	char* token = strtok(env_vars[i], "=");
        if (token != NULL && strcmp(token, key) == 0) {
            char buffer[BUFFER_SIZE];
            snprintf(buffer, BUFFER_SIZE, "%s=%s", key, value);

            if (strlen(buffer) < BUFFER_SIZE) {
                strcpy(env_vars[i], buffer);
                return 0;
            } else {
                return -1;
            }
        }
	    }
    return -1;
}

