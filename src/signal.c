/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 12:06:25 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/28 13:27:31 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

#include "ft_printf.h"
#include "minishell.h"

void	process_signal_handler(int signo)
{
	(void)signo;
	ft_printf("\n");
}

void	signal_handler(int signo)
{
	(void)signo;
	ft_printf("\n");
	display_prompt();
}
