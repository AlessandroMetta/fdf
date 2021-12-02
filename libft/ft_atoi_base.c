/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 10:03:37 by ametta            #+#    #+#             */
/*   Updated: 2021/12/02 17:10:48 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	checking(const char *str, size_t *i, int *sign)
{
	*i = 0;
	*sign = 1;
	while (ft_strchr(" \t\v\r\n\f", str[*i]))
		(*i)++;
	while (ft_strchr("-+", str[*i]))
	{
		if (str[*i] == '-')
			(*sign) = -1;
		(*i)++;
	}
}

int	ft_atoi_base(const char *str, int base)
{
	size_t	i;
	int		sign;
	size_t	num;

	num = 0;
	if (!str || base < 2 || base > 16)
		return (0);
	checking(str, &i, &sign);
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
