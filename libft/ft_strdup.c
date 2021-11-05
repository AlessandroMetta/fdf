/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:08:01 by ametta            #+#    #+#             */
/*   Updated: 2021/04/26 14:46:55 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicated;
	size_t	lenght;

	lenght = ft_strlen(s1) + 1;
	duplicated = (char *)ft_calloc(lenght, sizeof(char));
	ft_strlcpy(duplicated, s1, lenght);
	return (duplicated);
}
