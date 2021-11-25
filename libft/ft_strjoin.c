/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:58:31 by ametta            #+#    #+#             */
/*   Updated: 2021/11/10 12:58:34 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*str;
	int		c_str;
	int		c_s;

	c_str = 0;
	c_s = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[c_s] != '\0')
		str[c_str++] = s1[c_s++];
	c_s = 0;
	while (s2[c_s] != '\0')
		str[c_str++] = s2[c_s++];
	str[c_str] = '\0';
	return (str);
}
