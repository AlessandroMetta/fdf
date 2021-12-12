/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:10:34 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:11:41 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(int nbr, int base)
{
	char	*ref_base = "0123456789ABCDEF";

	if (nbr >= base)
	{
		ft_putnbr_base(nbr / base, base);
		ft_putnbr_base(nbr % base, base);
	}
	else
		write(1, &ref_base[nbr], 1);
}
