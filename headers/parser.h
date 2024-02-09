/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atereso- <atereso-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:22:35 by jbuny-fe          #+#    #+#             */
/*   Updated: 2023/05/18 11:23:21 by atereso-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "define.h"
# include "libft.h"

# define LEFT 1
# define RIGHT 2

t_tree		*node_creator(int id);
void		create_top_node(t_tree **tree, t_tree *node);
void		create_left_node(t_tree *previous, t_tree *new_node);
void		create_right_node(t_tree *previous, t_tree *node);
t_tree		*add_to_tree(int tokentype, t_tree *last_node);
t_tree		*pipes_cond(int tokentype, t_tree *aux, t_tree *node);
t_tree		*redir_cond(t_tree *aux, t_tree *node);
t_tree		*heredoc_cond(t_tree *last_node, t_tree *node);
t_heredoc	*make_heredoc(void);
ssize_t		get_heredoc_input(t_heredoc *heredoc, char *delimiter);
t_tree		*addtoken_to_tree(char **tokens);
int			token_manager(char *token);
char		*token_updater(char **tokens, int *i);
int			get_token_type(char *token);
t_tree		*parser_init(char *s);
int			syntax_checker(char *line);
void		*no_mem(void *p);
char		*str_expander(char *s);
void		free_tree(t_tree *bintree);
t_tree		*find_topof_tree(t_tree *bintree);
void		heredoc_handler(t_heredoc *heredoc);
int			check_direction(int direction, t_tree *node);
// void		close_heredocs(t_heredoc **all_heredocs);
#endif
