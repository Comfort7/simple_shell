#include <stdio.h>
#include <string.h>

struct Alias {
    char* alias_name;
    char* alias_command;
};

struct Alias aliases[10];

void print_alias()
{
	int i;

    for (i = 0; i < 10; i++) {
        if (aliases[i].alias_name != NULL) {
            printf("Alias: %s -> %s\n", aliases[i].alias_name, aliases[i].alias_command);
        }
    }
}

int set_alias(const char* name, const char* command)
{
	int i;

    for (i = 0; i < 10; i++) {
        if (aliases[i].alias_name == NULL) {
            aliases[i].alias_name = strdup(name);
            aliases[i].alias_command = strdup(command);
            return 0;
	}
    }
    return -1;
}

