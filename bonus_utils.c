/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 01:13:41 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/31 16:32:28 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	here_doc(char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	line = readline("here_doc => ");
	while (ft_strcmp(line, av[2]))
	{
		if(!line)
			break;
		free(line);
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		line = readline("here_doc => ");
	}
	free(line);
	close(fd);
}

char	*readline(char *str)
{
	char	*line;

	write(1, str, ft_strlen(str));
	line = get_next_line(0);
	return (line);
}