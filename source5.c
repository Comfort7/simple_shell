#include <stdio.h>
#include <string.h>

struct Alias {
    char* alias_name;
    char* alias_command;
};

struct Alias aliases[] = {
    {"ls", "ls --color=auto"},
    {NULL, NULL}
};

char* expand_alias(const char* command)
{
	int i;

    for (i = 0; aliases[i].alias_name != NULL; i++) {
        if (strcmp(aliases[i].alias_name, command) == 0) {
            return strdup(aliases[i].alias_command);
        }
    }
    return strdup(command);
}

