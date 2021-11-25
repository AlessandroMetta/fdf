/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_realloc_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:16:10 by ametta            #+#    #+#             */
/*   Updated: 2021/11/18 12:58:39 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char *ft_append(char *s1, char *s2)
{
	char	*s;
	int	i;
	int	j;

	i = 0;
	j = 0;
	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!s)
		return (NULL);
	while (s1[j] != '\0')
		s[i++] = s1[j++];
	j = 0;
	s[i++] = '\n';
	while (s2[j] != '\0')
		s[i++] = s2[j++];
	s[i++] = '\0';
	free(s1);
	return (s);
}

char	**map_create(int fd)
{
	char	*buff;
	char	*line;
	char	**splitted;

	buff = NULL;
	while (get_next_line(fd, &line))
	{
		if (!buff)
			buff = ft_strdup(line);
		else
			buff = ft_append(buff, line);
		free(line);
	}
	free(line);
	splitted = ft_split(buff, '\n');
	free(buff);
	return (splitted);
}
