/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:46:30 by ametta            #+#    #+#             */
/*   Updated: 2021/12/01 11:48:18 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **l_split)
{
	int	w;

	w = 0;
	while (l_split[w])
		free(l_split[w++]);
	free(l_split[w]);
	free(l_split);
}
