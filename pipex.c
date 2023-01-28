/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:57 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/28 03:25:21 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void errorshow(int type)
{
	if (type == 0)
		write(2,"command not found\n",19);
	if (type == 1)
		write(2,"not enoght arguments\n",22);
	if (type == 2)
		write(2,"no such file or directory ..\n",30);
}
int main(int ac, char **av, char **env)
{
	int		fd[2];
	int		pid[2];
	int		fd1;
	int		fd2;
	char	**cmd1;
	char	**cmd2;
	int		i;

	i = 0;
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	parsing(ac, av, env);
	if (ac != 5)
		errorshow(1);
	
	fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipe(fd);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		fd1 = open(av[1], O_RDONLY);
		if(fd1 == -1)
		{
			errorshow(2);
			exit(1);
		}
		dup2(fd1, 0);
		dup2(fd[1], 1);
		close(fd[0]);
		execve(av[2], cmd1, env);
		errorshow(0);
		exit(127);
	}
	else
	{
		waitpid(pid[0], NULL, 0);
		pid[1] = fork();
		if (pid[1] == 0)
		{
			dup2(fd[0], 0);
			dup2(fd2, 1);
			close(fd[1]);
			while(1);
			execve(av[3], cmd2, env);
			errorshow(0);
			exit(127);
		}
	}
	return (0);
}
