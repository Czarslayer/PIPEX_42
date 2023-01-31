/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:25:49 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/31 01:24:19 by mabahani         ###   ########.fr       */
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
# include "./libft/libft.h"
# include "pipex_bonus.h"

typedef struct s_pipex
{
	char	**cmd1;
	char	**cmd2;
	int		fd[2];
	int		pid[2];
	int		fd1;
	int		fd2;
	int		i;
}				t_pipex;

void	parsing(int ac, char **av, char **env);
void	errorshow(int type);
void	argemmenterror(int i, char **av);

#endif
