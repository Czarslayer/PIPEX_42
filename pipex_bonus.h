/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 22:12:50 by mabahani          #+#    #+#             */
/*   Updated: 2023/02/03 18:49:41 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <errno.h>
# include "./libft_tools/libft.h"
# include "./gnl/get_next_line.h"
# include "pipex.h"

# define READ 0
# define WRITE 1

void	parsing_bon(int ac, char **av, char **env, t_pipex *pipex);
void	command_splitter_bonus(t_pipex *pipex, char **av);
void	argemmenterror_bonus(int i, char **av);
void	here_doc(char **av);
char	*readline(char *str);
void	double_pointer(char **ptr);
char	*get_path_line(char **env);
char	*get_the_cmd(char *cmd, char **path);

#endif