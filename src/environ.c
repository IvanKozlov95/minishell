/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:16:52 by ivankozlov        #+#    #+#             */
/*   Updated: 2019/05/28 13:27:06 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chars.h"
#include "memory.h"
#include "ftstring.h"
#include "ft_printf.h"
#include "minishell.h"

t_dict	*g_env;

bool	valid_env_name(char *name)
{
	return (name && ft_isalpha(*name) && strisalnum(name));
}

char	*pair_to_str(t_dict_pair pair)
{
	char		*ret;
	size_t		key_len;
	size_t		val_len;

	key_len = ft_strlen(pair.key);
	val_len = ft_strlen(pair.val);
	ret = ft_strnew(key_len + val_len + 1);
	ft_strcat(ret, pair.key);
	ft_strcat(ret, "=");
	ft_strcat(ret, pair.val);
	return (ret);
}

void	init_env(void)
{
	size_t			i;
	extern char		**environ;
	char			*separator;

	i = -1;
	g_env = dict_init(0);
	while (environ[++i])
	{
		separator = ft_strchr((const char *)environ[i], '=');
		*separator = 0;
		dict_insert(g_env, environ[i], separator + 1);
	}
}
