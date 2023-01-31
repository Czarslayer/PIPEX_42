/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:17:43 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/31 02:13:10 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	double_pointer(char **ptr)
{
	int	i;

	i = 0;
	while (ptr && ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	if (ptr)
		free(ptr);
}

char	*get_path_line(char **env)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])))
		{
			line = ft_strdup(env[i] + 5);
			break ;
		}
		i++;
	}
	return (line);
}

char	*get_the_cmd(char *cmd, char **path)
{
	char	*tmp;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	if (!cmd || cmd[0] == '/' || cmd[0] == '.')
		return (NULL);
	i = 0;
	tmp = NULL;
	while (path && path[i])
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, X_OK) == 0)
			break ;
		free(tmp);
		i++;
	}
	if (access(tmp, X_OK) == 0)
		return (tmp);
	return (NULL);
}