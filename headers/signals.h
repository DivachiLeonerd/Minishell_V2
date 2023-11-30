#ifndef SIGNALS_H
#define SIGNALS_H

#include <signal.h>

void    sigmode_change(int mode);
void    normal_mode(int signum);
void    execution_mode(int signum);

#endif
