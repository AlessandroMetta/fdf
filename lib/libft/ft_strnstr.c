/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:09:33 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:11:41 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*temp;
	char	*needlestart;
	size_t	t;

	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (0);
	needlestart = (char *)needle;
	while (len)
	{
		temp = (char *)haystack;
		t = len;
		while (t-- && *haystack && *haystack == *needle)
		{
			haystack++;
			needle++;
			if (!*needle)
				return (temp);
		}
		haystack = temp + 1;
		needle = needlestart;
		len--;
	}
	return (NULL);
}
