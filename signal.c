/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:03:53 by lejimene          #+#    #+#             */
/*   Updated: 2023/09/21 19:59:20 by lejimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	void	handler(int sig)			// this is CTRL C
{
	(void)sig;								// sig is not used. but to bypass warning of unsed we call it.
	if (!g_gb.under_exec)					// if the shell is currently busy, do not do CTRL C. OTHERWISE:
	{
		ft_putstr_fd("\n", STDOUT_FILENO);	// NEW LINE
		rl_on_new_line();					// MOVE CURSOR 2 new line
		rl_replace_line("", 0);				// CLEARS INPUT (attention: Terminal does not change the visual representation)
		rl_redisplay();						// Refreshes the display to the current internal state.
		g_gb.exit_st = 1;					// sets the exit status to 1 (no idea for what its used)
	}
}

void	_signal_start(void)
{
	rl_catch_signals = 0;
	if (signal(SIGINT, handler) == SIG_ERR			// CTRL C
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR	)	// CTRL "\" -> ignore(SIG_IGN) the SIGQUIT signalr
//		|| signal(SIGTSTP, SIG_IGN) == SIG_ERR)		// CTRL Z is being ignored - - -not given in the task
		return ;									// CTRL D sends a NULL, inside the main while(1) loop the break gets activated
	
}