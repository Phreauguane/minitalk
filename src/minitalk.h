/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:32 by jde-meo           #+#    #+#             */
/*   Updated: 2024/01/15 15:55:33 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <libft.h>
# include <unistd.h>
# include <signal.h>

# define SUCCESS 0
# define FAILURE -1

void	exit_handler(char *msg);
void	verify_input(int ac, char **av);

#endif