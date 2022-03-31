/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-wak <cben-wak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:20:13 by cben-wak          #+#    #+#             */
/*   Updated: 2022/03/29 17:52:55 by cben-wak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset(t_vars *v)
{
		v->i = 0;
		v->c = 0;
		v->oldpid = v->newpid;
}

void	check(t_vars *v)
{
	char	bs;

	bs = 8;
	if ((v->lc >> 8) & 1)
		write (1, &bs, 1);
	reset(v);
}

void	ft_handler(int sig, struct __siginfo *info, void *p)
{
	static t_vars	v;

	p = NULL;
	if (info->si_pid)
		v.newpid = info->si_pid;
	if (v.oldpid != v.newpid)
		check(&v);
	if (sig == SIGUSR2)
		v.c = (1 << (7 - v.i)) | v.c;
	if (v.i == 7)
	{
		if (v.c == '\0')
			kill(info->si_pid, SIGUSR2);
		else
		{
			write(1, &v.c, 1);
			v.lc = v.c;
		}
		reset(&v);
	}
	else
		v.i++;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_handler;
	ft_putstr("PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
