/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-wak <cben-wak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:20:09 by cben-wak          #+#    #+#             */
/*   Updated: 2022/03/29 15:19:39 by cben-wak         ###   ########.fr       */
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
		usleep(700);
		i--;
	}
}

void	handl(int pid)
{
	(void)pid;
	write(1, "success", 8);
}

int	main(int ac, char *av[])
{
	int	pid;
	int	j;

	signal(SIGUSR2, handl);
	if (ac != 3)
	{
		write (1, "arg fail\n", 10);
		exit(1);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0)
	{
		write(1, "bad pid\n", 9);
		exit (1);
	}
	j = 0;
	while (av[2][j])
		ft_sender(av[2][j++], pid);
	ft_sender('\0', pid);
	return (0);
}
