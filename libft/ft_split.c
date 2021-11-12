/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:25:51 by ametta            #+#    #+#             */
/*   Updated: 2021/11/12 11:31:39 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(const char *line, const char chr)
{
	int i;
	int word_counter;

	i = 0;
	word_counter = 0;
	while (line[i] != '\0')
	{
		if (line[i] == chr)
			i++;
		else
		{
			word_counter++;
			while(line[i] != '\0' && line[i] != chr)
				i++;
		}
	}
	return (word_counter);
}

char **populate(const char *line, const char chr, char **line_split, int wc)
{
	int	i_w;
	int	i_c;
	int	w_l;

	i_w = 0;
	i_c = 0;
	while (i_w < wc)
	{
		if (line[i_c] != chr)
		{
			w_l = i_c;
			while (line[w_l] && line[w_l] != chr)
				w_l++;
			line_split[i_w] = (char *)malloc(sizeof(char) * (w_l - i_c + 1));
			if (!line_split[i_w])
				return (NULL);
			ft_memmove(line_split[i_w], line + i_c, (w_l - i_c));
			i_w++;
			i_c = w_l;
		}
		else
			i_c++;
	}
	return (line_split);
}

char	**ft_split(const char *line, const char chr)
{
	char	**line_splitted;
	int		wc;

	wc = word_counter(line, chr);
	if (!line)
		return (NULL);
	line_splitted = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!line_splitted)
		return (NULL);
	line_splitted[wc] = NULL;
	return (populate(line, chr, line_splitted, wc));
}
