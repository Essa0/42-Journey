/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:24 by issa              #+#    #+#             */
/*   Updated: 2026/04/29 17:23:04 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// done zeyad
#include "../../include/minishell.h"

static char	*expand_var(char *s, int *i, t_shell *sh)
{
	char	*key;
	char	*val;
	int		start;

	if (s[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(sh->exit_status));
	}
	start = *i;
	while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_') && s[*i] != '$')
		(*i)++;
	if (*i == start)
		return (ft_strdup("$"));
	key = ft_substr(s, start, *i - start);
	if (!key)
		return (NULL);
	val = get_env_val(sh->envp_shell, key);
	free(key);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

static char	*handle_sq(char *s, int *i)
{
	int		start;
	char	*part;

	start = ++(*i);
	while (s[*i] && s[*i] != '\'')
		(*i)++;
	if (!s[*i])
		return (NULL);
	part = ft_substr(s, start, *i - start);
	(*i)++;
	return (part);
}

static char	*get_dq_part(char *s, int *i, t_shell *sh)
{
	if (s[*i] == '$')
	{
		(*i)++;
		return (expand_var(s, i, sh));
	}
	return (ft_substr(s, (*i)++, 1));
}

static int	append_dq_part(char **res, char *s, int *i, t_shell *sh)
{
	char	*tmp;

	tmp = get_dq_part(s, i, sh);
	if (!tmp)
	{
		free(*res);
		*res = NULL;
		return (1);
	}
	*res = append(*res, tmp);
	if (!*res)
		return (1);
	return (0);
}

static char	*handle_dq(char *s, int *i, t_shell *sh)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		if (append_dq_part(&res, s, i, sh))
			return (NULL);
	}
	if (!s[*i])
	{
		free(res);
		return (NULL);
	}
	(*i)++;
	return (res);
}

static char	*handle_normal(char *s, int *i, t_shell *sh)
{
	if (s[*i] == '\'')
		return (handle_sq(s, i));
	if (s[*i] == '\"')
		return (handle_dq(s, i, sh));
	if (s[*i] == '$')
	{
		(*i)++;
		return (expand_var(s, i, sh));
	}
	return (ft_substr(s, (*i)++, 1));
}

char	*expand_string(char *str, t_shell *sh)
{
	int		i;
	char	*res;
	char	*part;

	i = 0;
	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (str[i])
	{
		part = handle_normal(str, &i, sh);
		if (!part)
		{
			free(res);
			return (NULL);
		}
		res = append(res, part);
		if (!res)
			return (NULL);
	}
	return (res);
}
