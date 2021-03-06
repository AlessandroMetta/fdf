/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 11:08:27 by avilla-m          #+#    #+#             */
/*   Updated: 2021/12/12 16:14:29 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_hash(t_flg *flg)
{
	flg->hash = 1;
}

void	set_space(t_flg *flg)
{
	if (flg->plus == 0)
		flg->space = 1;
}

void	set_plus(t_flg *flg)
{
	flg->plus = 1;
	flg->space = 0;
}

void	conv_n(int *ptr, int *n_ch, t_flg flg)
{
	if (flg.width || flg.minus || flg.zero || flg.width || flg.hash
		|| (flg.precision > -1 && !flg.only_dot) || flg.space
		|| flg.plus)
	{
		*n_ch = -1;
		return ;
	}
	*ptr = *n_ch;
}
