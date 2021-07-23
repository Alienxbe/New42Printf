/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 06:55:14 by mykman            #+#    #+#             */
/*   Updated: 2021/05/29 23:22:08 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_ubase(t_tag *tag, va_list args)
{
	char	*s;
	char	*tmp;

	s = NULL;
	tmp = NULL;
	if (tag->flags & FLAG_PRECISION && tag->flags & FLAG_ZERO && tag->prec >= 0)
		tag->flags ^= FLAG_ZERO;
	if (tag->type == U_INT)
		s = ft_ultoa_base(va_arg(args, unsigned int), tag->prec, BASE_DECI);
	else if (tag->type == LC_HEXA)
		s = ft_ultoa_base(va_arg(args, unsigned int), tag->prec, BASE_HEXA_L);
	else if (tag->type == UC_HEXA)
		s = ft_ultoa_base(va_arg(args, unsigned int), tag->prec, BASE_HEXA_U);
	else if (tag->type == PTR)
	{
		tmp = ft_ultoa_base(va_arg(args, unsigned long),
				tag->prec, BASE_HEXA_L);
		s = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (ft_print_type(tag, s));
}
