/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-wak <cben-wak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:20:09 by cben-wak          #+#    #+#             */
/*   Updated: 2022/03/29 21:37:36 by cben-wak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sender(char c, int pid)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = 1 & (c >> i);
		if (kill(pid, SIGUSR1 + bit) == -1)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
		usleep(500);
		i--;
	}
}

int	main(int ac, char *av[])
{
	int	pid;
	int	j;

	if (ac != 3)
	{
		write (1, "arg fail\n", 10);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0 || !pid)
	{
		write(1, "bad pid\n", 9);
		exit (1);
	}
	j = 0;
	while (av[2][j])
		ft_sender(av[2][j++], pid);
	return (0);
}
