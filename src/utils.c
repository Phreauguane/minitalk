/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 20:07:05 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/26 20:56:16 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	exit_handler(char *msg)
{
	ft_putstr_fd("\nError: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(FAILURE);
}
