/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:21:29 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/27 03:39:07 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "minishell.h"

int		unsetenv(char *name, char **args)
{
	if (!*args)
		print_minishell_message("%s unsetenv: Too few arguments.\n", 0, 0);
	else
		while (*args)
		{
			dict_remove(g_env, *args);
			args++;
		}
	return (0);
}
