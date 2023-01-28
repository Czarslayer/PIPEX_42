/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:57 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/28 21:08:31 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:57:57 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/28 18:50:49 by mabahani         ###   ########.fr       */
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

void first_child_process(t_pipex *pipex, char **av, char **env)
{
	close(pipex->fd[0]);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[1]);
	pipex->fd1 = open(av[1], O_RDONLY);
	dup2(pipex->fd1, 0);
	close(pipex->fd1);
	if (execve(av[2], pipex->cmd1, env) == -1)
		errorshow(0);
}

void second_child_process(t_pipex *pipex, char **av, char **env)
{
	close(pipex->fd[1]);
	dup2(pipex->fd[0], 0);
	close(pipex->fd[0]);
	pipex->fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(pipex->fd2, 1);
	close(pipex->fd2);
	if (execve(av[3], pipex->cmd2, env) == -1)
		errorshow(0);
}



int main(int ac, char **av, char **env)
{
	t_pipex		pipex;

	pipex.i = 0;
	pipex.cmd1 = ft_split(av[2], ' ');
	pipex.cmd2 = ft_split(av[3], ' ');
	parsing(ac, av, env);
	if (ac != 5)
		errorshow(1);
	pipe(pipex.fd);
	pipex.pid[0] = fork();
	if (pipex.pid[0] == 0)
		first_child_process(&pipex, av, env);
	else
	{
		pipex.pid[1] = fork();
		if (pipex.pid[1] == 0)
			second_child_process(&pipex, av, env);
		close(pipex.fd[0]);
		close(pipex.fd[1]);	
		waitpid(pipex.pid[0], NULL, 0);
		waitpid(pipex.pid[1], NULL, 0);
	}
	return (0);
}

