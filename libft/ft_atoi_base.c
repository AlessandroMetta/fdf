/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:03:37 by ametta            #+#    #+#             */
/*   Updated: 2021/12/01 11:54:24 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		sign;
	size_t	num;

	num = 0;
	i = 0;
	sign = 1;
	if (!str || base < 2 || base > 16)
		return (0);
	while (ft_strchr(" \t\v\r\n\f", str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_strchr("0123456789ABCDEFabcdef", str[i]))
	{
		num = (num * base);
		if (ft_strchr("0123456789", str[i]))
			num += str[i] - '0';
		else if (ft_strchr("abcdef", str[i]))
			num += str[i] - ('a' - 10);
		else if (ft_strchr("ABCDEF", str[i]))
			num += str[i] - ('A' - 10);
		else
			return (0);
		i++;
	}
	return (num * sign);
}
