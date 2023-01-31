/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:20:47 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/31 01:23:43 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
