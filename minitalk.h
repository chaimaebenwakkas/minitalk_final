/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cben-wak <cben-wak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:34:51 by cben-wak          #+#    #+#             */
/*   Updated: 2022/03/29 15:58:11 by cben-wak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars{
	int		i;
	char	c;
	int		oldpid;
	int		newpid;
	char	lc;
}	t_vars;

void	ft_putstr(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(unsigned long nb);

#endif
