/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:25:49 by mabahani          #+#    #+#             */
/*   Updated: 2023/02/03 21:34:33 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "./libft_tools/libft.h"

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	int		pid[2];
	int		fd1;
	int		fd2;
	int		status;
}				t_pipex;

void	parsing(int ac, char **av, char **env);
void	argemmenterror(int i, char **av);

void	parsing_bon(int ac, char **av, char **env, t_pipex *pipex);
void	command_splitter_bonus(t_pipex *pipex, char **av);
void	argemmenterror_bonus(int i, char **av);
void	here_doc(char **av);
char	*readline(char *str);
void	double_pointer(char **ptr);
char	*get_path_line(char **env);
char	*get_the_cmd(char *cmd, char **path);


#endif
