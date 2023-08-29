/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:52:15 by atereso-          #+#    #+#             */
/*   Updated: 2023/05/22 00:22:36 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../built-ins.h"
#include "../../define.h"
#include "../../minishell.h"
#include <errno.h>

static void	intrv_signal_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	return ;
}

static void	nintrv_signal_handler(int sig_num)
{
	if (sig_num == SIGQUIT || sig_num == SIGINT)
	{
		g_struct.chad_exitstatus = 4;
		exit(4);
	}
}

void	intr_behaviour(struct sigaction *act)
{
	act->sa_handler = intrv_signal_handler;
	act->sa_flags = SA_RESTART;
	sigaction(SIGINT, act, NULL);
	act->sa_handler = SIG_IGN;
	sigaction(SIGQUIT, act, NULL);
	return ;
}

void	nintr_behaviour(struct sigaction *act)
{
	act->sa_handler = nintrv_signal_handler;
	act->sa_flags = SA_RESTART;
	sigaction(SIGINT, act, NULL);
	sigaction(SIGQUIT, act, NULL);
	return ;
}
