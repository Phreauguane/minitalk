/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:30:23 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/28 16:57:12 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver;

void	verify_input(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
		exit_handler("Please use: ./client <server_pid> <message>");
	while (ft_isdigit(av[1][i]))
		i++;
	if (av[1][i])
		exit_handler("Wrong pid");
	if (av[2][0] == '\0')
		exit_handler("Empty message");
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	bits;

	(void)info;
	(void)context;
	if  (signum == SIGUSR2 || signum == SIGUSR1)
		g_receiver = 1;
	if (signum == SIGUSR2)
		bits++;
	else if (signum == SIGUSR1)
		ft_printf("Server successfuly received %d bytes\n", (bits + bits / 7) / 8);
}

void	send_char(char c, pid_t pid)
{
	int	bit_index;
	int	timer;

	bit_index = 7;
	while (bit_index >= 0)
	{
		timer = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_receiver == 0)
		{
			if (timer >= 50)
				exit_handler("No responce from server");
			timer++;
			usleep(1000);
		}
		g_receiver = 0;
		bit_index--;
	}
}

void	send_msg(pid_t pid, char *msg)
{
	while (*msg)
	{
		send_char(*msg, pid);
		msg++;
	}
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

int	main(int ac, char **av)
{
	pid_t	server;
	
	g_receiver = 0;
	verify_input(ac, av);
	server = ft_atoi(av[1]);
	config_signals();
	send_msg(server, av[2]);
	return (SUCCESS);
}
