#ifndef _def_H
#define _def_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YYSTYPE char *

#define LENGTH(x) sizeof(x)/sizeof((x)[0])

#define CMD_NUMBERS 100

struct simple_cmd {
    int argc;
    int append;
    char **args;
    char *input;
    char *output;
};
typedef struct simple_cmd* command;

struct command_list {
    command cmd;
    struct command_list* next;
};
typedef struct command_list* cmd_list;

struct ENV_HISTORY
{
	int start;
	int end;
	char *his_cmd[CMD_NUMBERS];
};
typedef struct ENV_HISTORY* Env_History;

void init();
void prompt();
void execute();
void init_temp_cmd();
void clear_temp_cmd(command cmd);
void stop();

#endif
