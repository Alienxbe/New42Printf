/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 00:32:07 by mykman            #+#    #+#             */
/*   Updated: 2021/05/14 11:07:41 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_s(t_tag *tag, va_list args)
{
	char	*s;

	s = (char *)va_arg(args, char *);
	if (!s)
		s = NULL_STR;
	if (!(tag->flags & FLAG_PRECISION) || tag->prec < 0
		|| tag->prec > (int)ft_strlen(s))
		s = ft_strdup(s);
	else
		s = ft_substr(s, 0, tag->prec);
	if (!s)
		return (MALLOC_ERROR);
	return (ft_print_type(tag, s));
}
