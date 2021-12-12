/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:10:25 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:11:41 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int		long_n;

	if (n < 0)
	{
		long_n = -(long int)n;
		write(fd, "-", 1);
	}
	else
		long_n = n;
	if (long_n > 9)
	{
		ft_putnbr_fd(long_n / 10, fd);
		ft_putchar_fd((long_n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(long_n + '0', fd);
}
