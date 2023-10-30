/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:30:26 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/29 17:05:27 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signum, siginfo_t *info, void *ucontent)
{
	static int	bit;
	static char	c;

	(void)ucontent;
	if (bit == 0)
	{
		bit = 0b10000000;
		c = 0;
	}
	if (signum == SIGUSR1)
		c |= bit;
	bit >>= 1;
	if (bit == 0 && c)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit_handler("Failed to send SIGUSR1 to client");
		return ;
	}
	if (kill(info->si_pid, SIGUSR2) == -1)
		exit_handler("Failed to send SIGUSR2 to client");
}

void	config_signals(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_handler;
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		exit_handler("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		exit_handler("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n", pid);
	while (1)
		config_signals();
	return (SUCCESS);
}
