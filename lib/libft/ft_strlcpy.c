/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:09:48 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:11:41 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (src[i] != 0)
	{
		if (i + 1 < size)
			dst[i] = src[i];
		if (i + 1 == size)
			dst[i] = 0;
		i++;
	}
	if (i + 1 <= size)
		dst[i] = 0;
	return (i);
}
