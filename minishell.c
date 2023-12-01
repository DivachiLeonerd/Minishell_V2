//This is going to be the main function
//if there are more functions here they should only call subroutines
//AND THERE SHOULD A REASON FOR THEM TO BE HERE
#include "headers/globals.h"
#include "headers/signals.h"
#include "headers/built-ins.h"
#include "headers/input.h"
#include "headers/common.h"

g_controller gvar;


int main(int argc, char **argv, char **envp)
{
    gvar.normal_act.sa_handler = normal_mode;
    gvar.execution_act.sa_handler = execution_mode;
    (void)argc;
    (void)argv;
    gvar.envp = build_envp(envp);
    char    *line;
    //signal handling for "Normal behaviour"
    
    sigmode_change(NORMAL);
    while (1)
    {
    //Input from User. Will always return the first valid command line
        line = get_user_input();
        if (!line)
            break;
    //change signal behaviour to "Executing mode"
       // sigmode_change(EXECUTION);
    //if input is correct, then start working the command line

    //after everything is done OR the command line is invalid
    //go back to the beginning 
        //sigmode_change(NORMAL);
    }
    //if user inputs a signal to end bash, free resources and return 0

    free_matrix(gvar.envp);
    return (0);
}
