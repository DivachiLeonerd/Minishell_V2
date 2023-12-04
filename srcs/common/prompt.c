#include <readline/readline.h>
#include "../../headers/globals.h"
#include "../../headers/libft.h"

static char	*homedir_subst(char *pwd)
{
	char	*aux;
	size_t	size;

	aux = str_expander(ft_strdup("$HOME"));
	if (ft_strncmp(pwd, aux, ft_strlen(aux)) == 0)
	{
		size = ft_strlen(aux);
		free(aux);
		aux = ft_substr(pwd, size, ft_strlen(pwd) - size);
		free(pwd);
		pwd = ft_strjoin("~", aux);
		free(aux);
		return (pwd);
	}
	free(aux);
	return (pwd);
}

char	*print_prompt(int r_flag)
{
	char	*pwd;
	char	*aux;
	char	prompt[200];

	pwd = getcwd(NULL, 0);
	pwd = homedir_subst(pwd);
	aux = ft_strjoin(PROMPT, pwd);
	free(pwd);
	pwd = ft_strjoin(aux, "\033[0m$ ");
	free(aux);
	ft_strlcpy(prompt, pwd, ft_strlen(pwd) + 1);
	free(pwd);
	if (r_flag)
		aux = readline(prompt);
	else
	{
		printf("%s", prompt);
		return (NULL);
	}
	return (aux);
}
