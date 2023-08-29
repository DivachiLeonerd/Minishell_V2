/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:18:23 by afonso            #+#    #+#             */
/*   Updated: 2023/05/23 17:17:51 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <stdlib.h>
# include "../define.h"
# include "../libft/libft.h"
# include <signal.h>

int		ft_echo(char **args);
char	**find_env_full_var(char *var_name);
char	*get_variable_name(char *message);
int		ft_pwd(void);
int		cd(char *pathname);
int		env(void);
int		export(char **args);
int		get_env_fd(char **envp);
int		how_many_arrays(char **double_ptr);
char	**build_envp(char **envp);
int		unset(char **args);
char	**env_realloc(char **envp, char **new_env, int numof_new_arrays,
			char *var);
void	add_var_to_env(char **new_env, char **old_env, char *var);
char	**replace_env_var(char **env, char *var);
void	delete_var_from_env(char **new_env, char **old_env, char *var);
int		is_builtin(char *command);
int		execute_non_builtin(char *command_name, char **argv);
void	ft_exit(void);
void	intr_behaviour(struct sigaction *act);
void	nintr_behaviour(struct sigaction *act);

#endif
