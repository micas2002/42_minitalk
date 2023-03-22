/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:40:45 by mibernar          #+#    #+#             */
/*   Updated: 2022/09/17 13:18:42 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char *message)
{
	int		i;
	int		bits;

	i = -1;
	while (message[++i])
	{
		bits = -1;
		while (++bits < 8)
		{
			if (message[i] & (0x80 >> bits))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(EXIT_FAILURE);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit(EXIT_FAILURE);
			}
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("%s\n", "client: invalid arguments");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	send_signal(pid, argv[2]);
	return (0);
}
