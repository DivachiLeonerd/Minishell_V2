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
# include "define.h"
# include "../libft/libft.h"
# include <signal.h>

int		ft_echo(char **args);
int		ft_pwd(void);
int		cd(char *pathname);
int		env(void);
int		export(char **args);
int		unset(char **args);
void	ft_exit(void);
int		is_builtin(char *command);

#endif
