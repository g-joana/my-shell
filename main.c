#include "minishell.h"

t_token **parser(char *input)
{
    // t_token **tokens;

    char **split = lexer(input, " ><|");
    print_split(split);

    return (NULL);
}

int main(int argc, char **argv, char **envp)
{
    char *input;
    t_main *main;

    if (argc < 2)
        return(0);
    
    main = malloc(sizeof (t_main));
    while (1)
    {
        readline(input);
        main->cmdline = parser(input);
        
    }
        


}
