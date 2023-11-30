#ifndef GLOBALS_H
#define GLOBALS_H

#include <signal.h>
#define NORMAL 0
#define EXECUTION 0

typedef struct g_controller
{
	int					chad_exitstatus;
	char				**envp;
	struct sigaction	normal_act;
	struct sigaction	execution_act;
	char				*command_line;
}g_controller;

extern g_controller gvar;

#endif
