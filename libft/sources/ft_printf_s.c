/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:50:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/04 17:33:52 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char *args)
{
	int		size;

	if (!args)
	{
		write (1, "(null)", 6);
		return (6);
	}
	size = 0;
	while (args[size] != '\0')
		size++;
	write (1, args, size);
	return (size);
}
