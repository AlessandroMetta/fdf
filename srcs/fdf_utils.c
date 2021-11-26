/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 10:19:26 by ametta            #+#    #+#             */
/*   Updated: 2021/11/26 16:16:02 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	dim_line(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	free_split(char **l_split)
{
	int	w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}

t_map	*ft_lstnew(int x, int y, int z, int color)
{
	t_map *elem;

	if (!(elem = malloc(sizeof(t_map))))
		return (NULL);
	elem->pos_x = x;
	elem->pos_y = y;
	elem->z = z;
	elem->color = color;
	elem->next = NULL;
	elem->down = NULL;
	return (elem);
}

void	ft_lstadd_back(t_map **lst, t_map *new)
{
	t_map *last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	if (new)
	{
		last->next = new;
	}
}
