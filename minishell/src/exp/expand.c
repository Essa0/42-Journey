/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:24 by issa              #+#    #+#             */
/*   Updated: 2026/04/09 01:17:25 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


static char	*expand_var(char *str, int *i, t_shell *shell)
{
	char	*var;
	char	*val;
	int		start;
	int		len;

	(*i)++;
	if (str[*i] == '?') // if it exit status
	{
		(*i)++;
		return (ft_itoa(shell->exit_status));
	}
	start = *i; // the start from after $
	while (str[*i] && is_var_char(str[*i]))
		(*i)++;
	len = *i - start; 
	if (len == 0)
		return (ft_strdup("$"));
	var = ft_substr(str, start, len);
	if (!var)
		return (NULL);
	val = get_env_val(shell->envp_shell, var);
	free(var);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

static char	*take_before_dollar(char *str, int *i)
{
	int		start;
	char	*before;

	if (!str)
		return (NULL);
	start = *i;
	while (str[*i] && str[*i] != '$') // take every char before $
			(*i)++;
	if (*i == start)
		return (NULL);
	before =  ft_substr(str, start, *i - start);
	if (!before)
		return (NULL);
	return (before);
}

static char	*append_part(char *result, char *part)
{
	char	*tmp;
		
	tmp = ft_strjoin(result, part);
	free(result);
	free(part);
	return (tmp);
}

static char	*dollar_process(char *str, int *i, t_shell *shell, char *resu)
{
	char	*part;

	// expand 
	part = expand_var(str, i, shell);
	if (!part)
	{
		free(resu);
		return (NULL);
	}
	// add it to part 
	return (append_part(resu, part));
}

char	*expand_string(char *str, t_shell *shell)
{
	char	*result;
	char	*part;    
	int		i;    

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		/* if we have a some data before $
		like 
		echo "hi from $HOME"
		we take part 
			 (hi from )&......
		first 
		*/
		part = take_before_dollar(str, &i);
		if (part)
			result = append_part(result, part);
		if (!result)
			return (NULL);
		if (str[i] == '$') // when we on $ go to expand it 
			result = dollar_process(str, &i, shell , result);
		if (!result)
			return (NULL);
	}
	return (result);
}
