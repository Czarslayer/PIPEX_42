/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:12:24 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/31 18:14:11 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	errorshow(int type)
{
	if (type == 1)
	{
		write(2, "Not Enoght Arguments \nOr You Wrote The 'here_doc' Name Wrong\n", 60);
		exit(1);
	}
}

void	argemmenterror(int i, char **av)
{
	if (i == 1)
	{
		write(2, "command not found: ", 20);
		write(2, av[0], ft_strlen(av[0]));
		write(2, "\n", 1);
	}
}

void	first_child_process(t_pipex *pipex, char **av, char **env)
{
	close(pipex->fd[0]);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[1]);
	pipex->fd1 = open(av[1], O_RDONLY);
	if (pipex->fd1 == -1)
	{
		perror("open");
		exit(1);
	}
	dup2(pipex->fd1, 0);
	close(pipex->fd1);
	execve(av[3], pipex->cmd1, env);
	argemmenterror(1, pipex->cmd1);
}

void	second_child_process(t_pipex *pipex, char **av, char **env)
{
	close(pipex->fd[1]);
	dup2(pipex->fd[0], 0);
	close(pipex->fd[0]);
	pipex->fd2 = open(av[5], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (pipex->fd2 == -1)
	{
		perror("open2");
		exit(1);
	}
	dup2(pipex->fd2, 1);
	close(pipex->fd2);
	execve(av[4], pipex->cmd2, env);
	argemmenterror(1, pipex->cmd2);
}

int	main(int ac, char **av, char **env)
{
	t_pipex		pipex;
	
	pipex.i = 0;
	if(ac == 6 && !ft_strcmp(av[1], "here_doc"))
		here_doc(av);
	else
		errorshow(1);
	pipex.cmd1 = ft_split(av[3], ' ');
	pipex.cmd2 = ft_split(av[4], ' ');
	parsing_bon(ac, av, env);
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
	return (unlink("here_doc"),0);
}
