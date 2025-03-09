#ifndef MINISHELL_H
# define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

enum e_type {
    CMD,
    ARG,
    PIPE,
    REDIR_IN,
    REDIR_OUT,
    HEREDOC,
    APPEND,
    FILE_IN,
    FILE_OUT,
} ;

typedef struct s_token
{
    char *value;
    int type;
} t_token;

typedef struct s_main
{
    t_token **cmdline;
} t_main;

// lexer.c
char	**lexer(char const *s, char *c);

// print.c
void	print_split(char **array);

#endif
