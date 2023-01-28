/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <mabahani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:25:49 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/28 18:32:33 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "./libft/libft.h"

typedef struct t_args{
    int		fd[2];
	int		pid[2];
	int		fd1;
	int		fd2;
	char	**cmd1;
	char	**cmd2;
	int		i;
}   l_args;

void    parsing(int ac, char **av, char **env);
void    errorshow(int type);


#endif

