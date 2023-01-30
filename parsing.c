/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:20:47 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/30 21:49:38 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
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

void	parsing(int ac, char **av, char **env)
{
	char	**path;
	char	*line;
	char	**cmd1;
	char	**cmd2;

	(void)ac;
	line = get_path_line(env);
	path = ft_split(line, ':');
	free(line);
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	av[2] = get_the_cmd(cmd1[0], path);
	av[3] = get_the_cmd(cmd2[0], path);
	double_pointer(cmd1);
	double_pointer(cmd2);
	double_pointer(path);
}
