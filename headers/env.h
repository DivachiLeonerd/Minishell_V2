#include <stdlib.h>

int     how_many_arrays(char **double_ptr);
char	**build_envp(char **envp);
void	free_bad_env_build(char **envp, int failed_index);
char	**env_realloc(char **envp, char **new_env, int numof_new_arrays, char *var);
void	free_matrix(char **envp);
