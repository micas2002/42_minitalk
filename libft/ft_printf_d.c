/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:04:23 by mibernar          #+#    #+#             */
/*   Updated: 2022/08/30 16:26:38 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_d(int args)
{
	char	*str;
	int		size;

	str = ft_itoa(args);
	size = ft_strlen(str);
	write(1, str, size);
	free (str);
	return (size);
}
