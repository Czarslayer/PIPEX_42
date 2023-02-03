/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:20:47 by mabahani          #+#    #+#             */
/*   Updated: 2023/02/03 18:58:30 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parsing_bon(int ac, char **av, char **env, t_pipex *pipex)

{
	char	**path;
	char	*line;
	char	**cmd1;
	char	**cmd2;

	(void)ac;
	command_splitter_bonus(pipex, av);
	line = get_path_line(env);
	path = ft_split(line, ':');
	free(line);
	cmd1 = ft_split(av[3], ' ');
	cmd2 = ft_split(av[4], ' ');
	av[3] = get_the_cmd(cmd1[0], path);
	av[4] = get_the_cmd(cmd2[0], path);
	double_pointer(cmd1);
	double_pointer(cmd2);
	double_pointer(path);
}
