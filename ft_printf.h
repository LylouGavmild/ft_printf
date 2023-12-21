/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:23:10 by abutet            #+#    #+#             */
/*   Updated: 2023/11/21 14:10:27 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_putchar_fd_len(char c);
int	ft_putstr_fd_len(char *s);
int	ft_putnbr_fd_len(int n);
int	ft_putunbr(unsigned int nbr);
int	ft_putp(long unsigned int nbr);
int	ft_puthex(unsigned int nbr, char c);

#endif