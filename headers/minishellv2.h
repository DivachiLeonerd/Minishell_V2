/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellv2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:44:07 by atereso-          #+#    #+#             */
/*   Updated: 2023/07/20 18:44:08 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
 #define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <curses.h>
#include <stdlib.h>
#include <readline/history.h>
#include <readline/readline.h>
#include "../libft/libft.h"
#include "env.h"


typedef struct  s_global
{
    char    **env;
    int     chad_exitstatus;
}g_struct;

extern g_struct gvar;

char    *get_env_var(char *env_line);
char    *get_env_line(char **env);
char    *get_prompt_line();
char    *print_prompt();
char    *get_new_cwd(char   *cwd);
int is_line_blank(char *line);

#endif
