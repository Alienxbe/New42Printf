/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 06:55:14 by mykman            #+#    #+#             */
/*   Updated: 2021/07/24 01:50:38 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*prefix(char *s, t_type type)
{
	char	*tmp;

	if (type == UC_HEXA)
		tmp = ft_strjoin("0X", s);
	else
		tmp = ft_strjoin("0x", s);
	if (s)
		free(s);
	return (tmp);
}

int	ft_type_ubase(t_tag *tag, va_list args)
{
	char	*s;

	s = NULL;
	if (tag->flags & FLAG_PRECISION && tag->flags & FLAG_ZERO && tag->prec >= 0)
		tag->flags ^= FLAG_ZERO;
	if (tag->type == U_INT)
		s = ft_ultoa_base(va_arg(args, unsigned int), tag->prec, BASE_DECI);
	else if (tag->type == LC_HEXA)
		s = ft_ultoa_base(va_arg(args, unsigned int), tag->prec, BASE_HEXA_L);
	else if (tag->type == UC_HEXA)
		s = ft_ultoa_base(va_arg(args, unsigned int), tag->prec, BASE_HEXA_U);
	else if (tag->type == PTR)
		s = ft_ultoa_base(va_arg(args, unsigned long), tag->prec, BASE_HEXA_L);
	if ((tag->flags & FLAG_HASHTAG && (tag->type == LC_HEXA
				|| tag->type == UC_HEXA)) || tag->type == PTR)
		s = prefix(s, tag->type);
	return (ft_print_type(tag, s));
}
