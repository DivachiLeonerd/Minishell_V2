#include "../../headers/signals.h"
#include <signal.h>
#include <stdio.h>
#include "../../headers/globals.h"

void    normal_mode(int signum)
{
    if (signum == SIGINT)
        printf("\n");
}

//Only this function will be called because it will handle all signal "modes"
//mode 0 is Normal Mode and mode 1 is Execution Mode
void sigmode_change(int mode)
{
    if (mode == 0)
    {
        gvar.normal_act.sa_handler = normal_mode;
        //'^C'
        sigaction(SIGINT, &(gvar.normal_act), NULL);
        //'^Z'
        sigaction(SIGSTOP, &(gvar.normal_act), NULL);
        //'^\'
        sigaction(SIGQUIT,  &(gvar.normal_act), NULL);
    }
    if (mode == 1)
    {
        gvar.execution_act.sa_handler = SIG_DFL;
        sigaction(SIGINT, &(gvar.execution_act), NULL);
        sigaction(SIGSTOP, &(gvar.execution_act), NULL);
        sigaction(SIGQUIT, &(gvar.execution_act), NULL);
    }
}
