/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoremyk <dgoremyk@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:17:09 by dgoremyk          #+#    #+#             */
/*   Updated: 2023/05/24 20:14:26 by dgoremyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ignore_ctrl_bslash(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = SIG_IGN;
	sigaction(SIGQUIT, &sa, NULL);
}

void	ctrl_c_interactive(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_exit_status = 130;
}

/// @brief default signal flow
/// ctrl-backslash is ignored
/// ctrl-C displays new prompt
/// @param  
void	sig_interactive(void)
{
	struct sigaction	sa;

	ignore_ctrl_bslash();
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &ctrl_c_interactive;
	sigaction(SIGINT, &sa, NULL);
}

void	ctrl_c_ctrl_bslash_noninteractive(int sig)
{
	if (sig == SIGQUIT)
	{
		g_exit_status = 128 + sig;
		write(1, "quit\n", 5);
		rl_on_new_line();
	}
	else if (sig == SIGINT)
	{
		g_exit_status = 128 + sig;
		write(1, "\n", 1);
		rl_on_new_line();
	}
}

/// @brief for child processes usage 
void	sig_noninteractive(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = &ctrl_c_ctrl_bslash_noninteractive;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}
