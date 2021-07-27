/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:39:41 by mykman            #+#    #+#             */
/*   Updated: 2021/07/27 21:38:39 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_d(t_tag *tag, va_list args)
{
	int		n;
	char	pos_sign_char;

	n = (int)va_arg(args, int);
	pos_sign_char = 0;
	if (tag->flags & FLAG_PRECISION && tag->flags & FLAG_ZERO && tag->prec >= 0)
		tag->flags ^= FLAG_ZERO;
	if (n < 0 && tag->flags & FLAG_ZERO)
		tag->prec = tag->width - 1;
	if (tag->flags & FLAG_PLUS)
		pos_sign_char = '+';
	else if (tag->flags & FLAG_SPACE)
		pos_sign_char = ' ';
	return (ft_print_type(tag, ft_printf_itoa(n, tag->prec, pos_sign_char)));
}
