/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   totest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabahani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:49:12 by mabahani          #+#    #+#             */
/*   Updated: 2023/01/27 23:01:45 by mabahani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
// i need to test if execve works
int main(int ac, char **av, char **env)
{
    char **test = ft_split(av[1], ' ');
    execve("/bin/sleep", test, env);
}