/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:55:45 by mykman            #+#    #+#             */
/*   Updated: 2021/05/24 14:16:44 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_flags(const char **format)
{
	int		flags;
	char	*pos;

	flags = 0;
	pos = ft_strchr(FLAGS, **format);
	while (pos)
	{
		flags |= 1 << (pos - FLAGS);
		pos = ft_strchr(FLAGS, *++*format);
	}
	return (flags);
}

static int	ft_get_width(const char **format, va_list args)
{
	int	width;

	width = 0;
	if (ft_isdigit(**format))
	{
		width = ft_atoi(*format);
		*format += ft_intsize(width, 0);
	}
	else if (**format == '*')
	{
		width = (int)va_arg(args, int);
		(*format)++;
	}
	return (width);
}

static int	ft_get_prec(const char **format, va_list args, t_tag *tag)
{
	int	prec;

	if (**format != '.')
		return (1);
	tag->flags |= FLAG_PRECISION;
	if (*++*format == '*')
	{
		prec = va_arg(args, int);
		(*format)++;
	}
	else
	{
		prec = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	return (prec);
}

t_tag	*ft_create_tag(const char **format, va_list args)
{
	t_tag	*tag;

	tag = (t_tag *)malloc(sizeof(t_tag));
	if (!tag)
		return (NULL);
	tag->type = NONE;
	if (!++*format)
		return (tag);
	tag->flags = ft_get_flags(format);
	tag->width = ft_get_width(format, args);
	tag->prec = ft_get_prec(format, args, tag);
	tag->type = (t_type)ft_index(TYPES, **format);
	if (tag->width < 0)
	{
		tag->width = -tag->width;
		tag->flags |= FLAG_MINUS;
	}
	if (tag->flags & FLAG_MINUS && tag->flags & FLAG_ZERO)
		tag->flags ^= FLAG_ZERO;
	return (tag);
}
