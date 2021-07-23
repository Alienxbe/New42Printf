/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 02:19:32 by mykman            #+#    #+#             */
/*   Updated: 2021/05/24 13:08:13 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_type(t_tag *tag, char *s)
{
	char	c_pad;

	c_pad = ' ';
	if (tag->flags & FLAG_ZERO)
		c_pad = '0';
	if (!s)
		return (MALLOC_ERROR);
	tag->width -= ft_strlen(s);
	if (!*s && tag->type == 0)
		tag->width--;
	ft_padding(c_pad, tag->width * ((tag->flags & FLAG_MINUS) <= 0));
	ft_putstr_fd(s, 1);
	if (!*s && tag->type == 0)
		ft_putchar_fd('\0', 1);
	ft_padding(c_pad, tag->width * ((tag->flags & FLAG_MINUS) > 0));
	if (tag->width < 0)
		tag->width = 0;
	tag->width += ft_strlen(s);
	if (!*s && tag->type == 0)
		tag->width++;
	free(s);
	return (tag->width);
}
