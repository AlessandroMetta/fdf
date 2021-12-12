/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:13:22 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:14:29 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, int fd)
{
	long int		long_n;

	if (n < 0)
		long_n = -(long int)n;
	else
		long_n = n;
	if (long_n > 9)
	{
		ft_putnbr_printf(long_n / 10, fd);
		ft_putchar_printf((long_n % 10) + '0', fd);
	}
	else
		ft_putchar_printf(long_n + '0', fd);
}
