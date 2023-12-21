/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:17:04 by abutet            #+#    #+#             */
/*   Updated: 2023/11/20 11:17:43 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_putdigit(int n)
{
	char	c;

	c = n + 48;
	write(1, &c, 1);
}

int	ft_putunbr(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putunbr(nbr / 10);
		len += ft_putunbr(nbr % 10);
	}
	else
	{
		ft_putdigit(nbr);
		len++;
	}
	return (len);
}
