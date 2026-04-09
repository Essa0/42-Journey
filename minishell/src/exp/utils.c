/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:22:20 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:22:38 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_var_char(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static int	is_tilde_expansion(char *str)
{
	return (str[0] == '~' && (str[1] == '\0' || str[1] == '/'));
}

char	*expand_tilde(char *str, char **envp)
{
	char	*home;
	char	*result;

	if (!is_tilde_expansion(str))
		return (ft_strdup(str));
	home = get_env_val(envp, "HOME");
	if (!home)
		return (ft_strdup(str));
	if (str[1] == '\0')
		return (ft_strdup(home));
	result = ft_strjoin(home, str + 1);
	return (result);
}