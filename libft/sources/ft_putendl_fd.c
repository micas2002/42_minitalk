/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:40:19 by mibernar          #+#    #+#             */
/*   Updated: 2021/10/28 15:02:43 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		write(fd, &s[x], 1);
		x++;
	}
	write(fd, "\n", 1);
}