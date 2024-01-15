/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:07:05 by jde-meo           #+#    #+#             */
/*   Updated: 2024/01/15 15:55:21 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	exit_handler(char *msg)
{
	ft_putstr_fd("\nError: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(FAILURE);
}
