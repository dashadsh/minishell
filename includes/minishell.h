/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:46:58 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/04/12 23:46:58 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
// stdio should be included before readline library
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include "../library/libft/libft.h"

# define MAX_TOKEN_SIZE 1024

int		g_exit_status;

typedef struct s_envp
{
	char			*key;
	char			*value;
	int				sorted;
	struct s_envp	*next;
}					t_envp;

typedef struct s_token
{
	char			*string;
	int				type;
	int				quote_type;
	struct s_token	*next;
}					t_token;

typedef struct s_outs
{
	char			*str;
	int				append;
	struct s_outs	*next;
}					t_outs;

typedef struct s_ins
{
	char			*str;
	int				heredoc;
	struct s_ins	*next;
}					t_ins;

typedef struct s_cmdgroup
{
	char				**cmd;
	t_ins				*ins;
	t_outs				*outs;
	int					pid;
	int					pipe[2];
	int					infile;
	int					outfile;
	char				*str;
	struct s_cmdgroup	*prev;
	struct s_cmdgroup	*next;
}						t_cmdgroup;

typedef struct s_data
{		
	char		*input;
	t_token		*token_lst;
	t_envp		*env_lst;
	t_cmdgroup	*cmdgroup;
}	t_data;

enum	e_quote_types
{
	NO_Q,
	S_Q,
	D_Q,
};

enum	e_token_types
{
	SEP,
	WORD,
	PIPE,
	IN_RED,
	OUT_RED,
	HERE_DOC,
	APP_RED,
};

typedef struct s_idx
{
	int	i;
	int	j;
}	t_idx;

// main.c
void	welcome(int argc, char **argv);
int		run_minishell(t_data *data);
void	minishell_loop(t_data *data);
int		main(int ac, char **av, char **envp);

//---------------BUILTINS-----------------//
// cd.c
void	cd_home(t_data *data);
void	ft_cd(t_data *data, char **str);

// echo.c
void	ft_echo(char **s);

// env.c
void	ft_env(t_data *data, char **str);

// export.c
int		issmaller(char *str, char *str2);
t_envp	*set_min(t_data *data);
void	export_print(t_data *data);
int		is_update(t_data *data, char *key, char *value);
int		export(t_data *data, char **var);

// isbuilin.c
int		isbuiltin(t_cmdgroup *group);
void	execbn(t_data *data, t_cmdgroup *group);
void	reset(t_data *data);

// pwd.c
void	ft_pwd(void);

// unset.c
void	unset_free(t_envp *ptr);
int		check(char **key);
int		ft_unset(t_data *data, char **key);

//---------------CMDGROUP_INIT-----------------//
// cmd_path.c
t_envp	*pathfinder(t_data *data);
void	add_path(t_cmdgroup *group, char **paths);
void	get_cmdpath(t_data *data);

// group_init.c
void	insert_end_outs(t_token *token, t_cmdgroup *group);
void	insert_end_ins(t_token *token, t_cmdgroup *group);
t_token	*add_group(t_data *data, t_token *token);
void	cmd_init(t_data *data);

// group_utils.c
int		arrlen(char **arr);
void	ft_clarr(char **str);
char	*ft_strjoin2(char *s1, char *s2, char c);

int		init_here_doc(char *delimeter);
int		init_fds(t_data *data);
void	execute(t_data *data);
void	free_all(t_data *data);
void	export_print(t_data *data);
char	*ft_strdup2(const char *str, int len);
char	*ft_strdup1(const char *str);

//---------------ENV_INIT-----------------//
// envplist_handler.c
char	*ft_strdup2(const char *str, int len);
void	envplist_handler(t_envp **head, char **envp);
t_envp	*create_envp_node(char **data);
void	envp_add_back(t_envp **lst, t_envp *new);
t_envp	*envp_last(t_envp *lst);
// char	*ft_strdup1(const char *str);

//---------------EXECUTION-----------------//
// execute.c
void	in_handler(t_cmdgroup *group);
void	out_handler(t_cmdgroup *group);
void	in_out_handler(t_cmdgroup *group);
void	child_process(t_cmdgroup *group);
void	execute(t_data *data);

// open_fds.c
int		here_doc2(char *delimeter);
int		here_doc(char *delimeter);
void	outfile_handler(t_cmdgroup *group);
int		infile_handler(t_cmdgroup *group);
int		init_fds(t_data *data);

// utils.c
void	pclose_pipes(t_cmdgroup *group);
void	parent_wait(t_cmdgroup *group);
void	ft_default(int stdin, int stdout);

//---------------FT_FREE-----------------//
// ft_free.c
void	free_ins(t_ins **ptr);
void	free_outs(t_outs **ptr);
void	free_cmdgroup(t_data *data);
void	exit_free(t_data *data);
void	exec_free(t_data *data);
//---------------PARSING-----------------//
// 01early_err.c
int		early_err(t_data *data);

// 01early_err_utils.c
int		pipes_err(char *input);
int		spaces_err(char *input);
int		quotes_err(char *s);
int		spec_char_err(char *input);
int		redirection_err(char *input);

// 01early_err_utils2.c
int		redirection_err_s_in(char *s, int *i);
int		redirection_err_s_out(char *s, int *i);
int		redirection_err_d_in(char *s, int *i);
int		redirection_err_d_out(char *s, int *i);

// 01early_err_utils3.c
int		skip_spaces(char *str);
int		skip_quotes(char *str, char quote);

// 02parser.c
void	parser(t_data *data);

// 02parser_utils.c
void	remove_consequtive_quotes(char *input);
void	free_token_lst(t_token **token_lst);
// void	print_full_token_data(t_data *data);
// void	print_token_string(t_data *data);

// 03tokenizer.c
void	tokenizer(t_token **token_lst, char *input);

// 03tokenizer_init.c
t_token	*init_in_quotes(char *s, int *i, char quote);
t_token	*init_pipe_or_sep(char *s, int *i, char pipe_or_sep);
t_token	*init_single_redirection(char *s, int *i, char in_or_out);
t_token	*init_double_redirection(char *s, int *i, char in_or_out);
t_token	*init_word(char *s, int *i);

// 03tokenizer_utils.c
t_token	*token_last(t_token *lst);
void	token_add_back(t_token **lst, t_token *new);
void	remove_quotes(char *s);
int		find_end(char *str, char *possible_sep);

// 04expander_init1.c
void	init_exit_status(char **new_ptr, t_idx *idx);
void	init_single_dollar(char **new_ptr, t_idx *idx);
void	expand_remainder(char **new_ptr, t_idx *idx, char *token, t_data *data);
void	copy_token_char(char **new_ptr, t_idx *idx, char c);
// 04expander_init2.c
int		ft_strcmp(char *s1, char *s2);
char	*find_envp_value(t_envp *env_lst, char *var_name);
char	*create_var_from_token(char *token, t_idx *idx);
void	copy_env_var_value(char **new_ptr, t_idx *idx, char *env_var);
void	init_env_var(char **new_ptr, t_idx *idx, char *token, t_data *data);

// 04expander_utils.c
int		dollar_in_str(char *s);
char	*get_exit_status(void);

// 04expander.c
void	process_expansion(char *token, t_data *data, t_idx *idx, char **exp);
char	*expand_token(char *token, t_data *data);
void	expand_token_lst(t_data *data);

//---------------SIGNALS-----------------//
//signals1.c
void	ignore_ctrl_bslash(void);
void	ctrl_c_interactive(int sig);
void	sig_interactive(void);
void	ctrl_c_ctrl_bslash_noninteractive(int sig);
void	sig_noninteractive(void);

//signals2.c
void	ctrl_c_heredoc(int sig);
void	sig_heredoc(void);
void	ctrl_c_heredoc_parent(int sig);
void	sig_parent_heredoc2(void);

#endif