/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ametta <ametta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:12:21 by ametta            #+#    #+#             */
/*   Updated: 2021/12/12 16:14:29 by ametta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_zero(t_flg *flg)
{
	if (flg->minus == 0)
		flg->zero = 1;
}

void	set_minus(t_flg *flg)
{
	flg->minus = 1;
	flg->zero = 0;
}

void	set_width(const char **in, t_flg *flg, va_list ap)
{
	if (**in == '*')
	{
		flg->width = va_arg(ap, int);
		if (flg->width < 0)
		{
			flg->minus = 1;
			flg->zero = 0;
			flg->width *= -1;
		}
		(*in)++;
	}
	else if ((**in > '0' && **in <= '9'))
	{
		while (**in >= '0' && **in <= '9')
		{
			flg->width *= 10;
			flg->width += **in - '0';
			(*in)++;
		}
	}
}

void	set_precision(const char **in, t_flg *flg, va_list ap)
{
	(*in)++;
	if (**in == '*')
	{
		flg->precision = va_arg(ap, int);
		if (flg->precision < 0)
			flg->precision = -1;
		(*in)++;
	}
	else if ((**in >= '0' && **in <= '9'))
	{
		flg->precision = 0;
		while (**in >= '0' && **in <= '9')
		{
			flg->precision *= 10;
			flg->precision += **in - '0';
			(*in)++;
		}
	}
	else
		set_only_dot(flg);
	if (flg->precision == 0)
		set_only_dot(flg);
}

void	set_only_dot(t_flg *flg)
{
	flg->only_dot = 1;
	flg->precision = 0;
}
