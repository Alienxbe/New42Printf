/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:39:41 by mykman            #+#    #+#             */
/*   Updated: 2021/05/24 14:33:10 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_d(t_tag *tag, va_list args)
{
	int	n;

	n = (int)va_arg(args, int);
	if (tag->flags & FLAG_PRECISION && tag->flags & FLAG_ZERO && tag->prec >= 0)
		tag->flags ^= FLAG_ZERO;
	if (n < 0 && tag->flags & FLAG_ZERO)
		tag->prec = tag->width - 1;
	return (ft_print_type(tag, ft_itoa(n, tag->prec)));
}
