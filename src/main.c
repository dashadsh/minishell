/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:21:19 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/16 10:21:19 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	welcome(int argc, char **argv)
{
	if (argc > 1 && ft_strcmp(argv[1], "nested"))
		exit(printf("minishell: %s: no such file or directory\n", argv[1]));
	printf("%s   ****************************************\n",
		"\033[0;32m");
	printf("   *        welcome to minishell          *\n");
	printf("   *%s   created by Marvellous and Daria    %s*\n",
		"\033[0;33m", "\033[0;32m");
	printf("   ****************************************\n%s",
		"\033[0m");
}

int	run_minishell(t_data *data)
{
	if (early_err(data) == -1)
	{
		g_exit_status = 2;
		return (-1);
	}
	parser(data);
	cmd_init(data);
	get_cmdpath(data);
	if (!init_fds(data))
		return (exec_free(data), 0);
	execute(data);
	exec_free(data);
	return (0);
}

void	minishell_loop(t_data *data)
{
	while (1)
	{
		sig_interactive();
		data->input = readline("minishell$ ");
		if (!data->input)
		{
			write(1, "exit\n", 5);
			exit_free(data);
			exit(0);
		}
		if (ft_strlen(data->input) > 0)
		{
			add_history(data->input);
			run_minishell(data);
		}
		else
			free(data->input);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	*data;

	welcome(ac, av);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (printf("Error: malloc failure (main)"), 1);
	g_exit_status = 0;
	pre_env(data, ac, av, envp);
	minishell_loop(data);
	return (0);
}
