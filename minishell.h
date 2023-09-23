/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:27:03 by lejimene          #+#    #+#             */
/*   Updated: 2023/09/23 19:04:25 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

#define READ_END 0
#define WRITE_END 1
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <limits.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <stdbool.h>
# include <dirent.h>
# include <fcntl.h>
# include "./printf/include/ft_printf.h"
# include "./printf/include/libft.h"

typedef struct s_env
{
	char			*env;
	char			*var;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_gb
{
	int		under_exec;
	int		exit_st;
	t_env	*env;
}	t_gb;


typedef enum e_token
{
	PIPE,
	HEREDOC,
	LPR,
	RPR,
	AND,
	OR,
	APPEND,
	OUT,
	IN,
	NOT,
	END
}t_token;

typedef struct s_redir
{
	t_token			tok;
	char			*file;
	bool			flg;
	int				fd;
	struct s_redir	*lchild;
	struct s_redir	*rchild;
}t_redir;

typedef struct s_node
{
	char ***tokens;
	int		num_commands;
	    struct t_node *lchild; // Left child
    struct t_node *rchild; // Right child
}t_node;

extern t_gb	g_gb;

void	_signal_start(void);
t_token	check_token(char c1, char c2);
bool	check_tok(char *s);
t_node *tokenize(char *input, const char *delimiter, char **env);
t_node *parsing(char *input, char **env);
void free_args(char **args);
int count_args(char **args);
void pipe_(t_node *root);
char *strtok_(char *str, const char *delim);






//	BUILT-INS
int		my_pwd(void);
int		my_env(t_env *env);
/*
	missing:
	- echo

	- exit
	- export
	- unset
*/
int		my_cd(char **args, t_env *env);








#endif