/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-wak <cben-wak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:20:13 by cben-wak          #+#    #+#             */
/*   Updated: 2022/03/29 21:37:47 by cben-wak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, struct __siginfo *info, void *p)
{
	static int	i;
	static char	c;
	static int	oldpid;
	static int	newpid;

	p = NULL;
	if (info->si_pid)
		newpid = info->si_pid;
	if (oldpid != newpid)
	{
		write(1, "\n", 1);
		i = 0;
		c = 0;
		oldpid = newpid;
	}
	if (sig == SIGUSR2)
		c = (1 << (7 - i)) | c;
	if (i == 7)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
		i++;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}


