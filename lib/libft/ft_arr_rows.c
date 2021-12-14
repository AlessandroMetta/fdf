/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_rows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:07:58 by ametta            #+#    #+#             */
/*   Updated: 2021/12/14 14:08:06 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_arr_rows(char **arr)
{
	int	i;
	int	j;

	if (!arr)
		return (-1);
	i = 0;
	j = 0;
	while (arr[i])
	{
		if ((int) ft_strlen(arr[i]) > j)
			j = ft_strlen(arr[i]);
		i++;
	}
	return (j);
}
