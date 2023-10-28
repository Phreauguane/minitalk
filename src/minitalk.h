/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:33:32 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/28 15:20:46 by jde-meo          ###   ########.fr       */
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

#endif