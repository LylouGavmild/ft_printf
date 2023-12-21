/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:38:03 by abutet            #+#    #+#             */
/*   Updated: 2023/11/20 10:38:43 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_get_size(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_fd_len(int n)
{
	int	len;

	ft_putnbr_fd(n, 1);
	len = ft_get_size(n);
	if (n < 0)
		len++;
	return (len);
}
