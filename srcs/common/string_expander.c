#include <stdlib.h>
#include "../../headers/globals.h"
#include "../../headers/libft.h"

//varname is a env variable token like: "$HOME"

char    *str_expander(char *varname)
{
    //between single and double quotes
    //if it's single quotes, it's taken literally
    //if it's double quotes, it can be taken as a "meta token"
    //if it has dollar sign, it's a meta token
    //both single and double quotes care about whitespace inside of them

    int i;

    i = 0;
    if (gvar.envp == NULL)
        return (NULL);
    while (1)
    {
        if (gvar.envp[i] == NULL)
            return (NULL);
        if (ft_strncmp(varname, &(gvar.envp[i][1]), ft_strlen(varname)) == 0)
        {
            return (ft_substr(&(gvar.envp[i][1]), ft_strlen(gvar.envp[i]) + 1));
        }
        i++;
    }


}
