/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishellv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 18:33:51 by atereso-          #+#    #+#             */
/*   Updated: 2023/07/20 18:33:52 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishellv2.h"

g_struct gvar;

int main(int argc, char **argv, char **env)
{
    gvar.env = build_envp(env);

    get_prompt_line();
    
}
