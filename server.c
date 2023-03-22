/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:40:36 by mibernar          #+#    #+#             */
/*   Updated: 2022/10/03 12:09:02 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_output(int signum)
{
	static char	c = 0xFF;
	static int	bits = 0;
			
	if (signum == SIGUSR1)
		c |= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		c = 0xFF;
		bits = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("%s: %d\n", "PID", pid);
	signal(SIGUSR1, write_output);
	signal(SIGUSR2, write_output);
	while (1)
		pause();
}
