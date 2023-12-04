#ifndef GLOBALS_H
#define GLOBALS_H

# include <stdlib.h>
#include <signal.h>
#define NORMAL 0
#define EXECUTION 0

typedef struct s_heredoc
{
	int				pipe_fd[2];
	char			*delimiter;
	ssize_t			bytes_stored;
}t_heredoc;

typedef struct s_tree
{
	int				tokentype;
	char			**args;
	t_heredoc		*heredoc;
	struct s_tree	*left_branch;
	struct s_tree	*right_branch;
	struct s_tree	*back;
}t_tree;

# define I_REDIR 1
# define O_REDIR 2
# define PIPE 3
# define HEREDOC 4
# define APPEND 5
# define BUILTIN 6
# define EXECUTABLE 7
# define WORD 8
# define NODE_WORTHY tokentype != WORD
# define PROMPT "\033[1;32mPequenaConcha:\033[1;34m"
# define COMMAND (node->tokentype == BUILTIN || node->tokentype == EXECUTABLE)
# define REDIR (node->tokentype == I_REDIR || node->tokentype == O_REDIR || node->tokentype == APPEND || node->tokentype == HEREDOC)
# define SPECIAL_TOKEN (tokentype == PIPE || tokentype == I_REDIR || tokentype == O_REDIR || tokentype == APPEND || tokentype == HEREDOC)

void	free_matrix(char **envp);
char	*find_command_path(char *command);

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
