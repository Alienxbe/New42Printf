/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:21:31 by mykman            #+#    #+#             */
/*   Updated: 2021/07/24 01:22:42 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

t_print	**init_type_table(void)
{
	t_print	**table;

	table = malloc(sizeof(t_print *) * LENGTH);
	if (!table)
		return (NULL);
	table[CHAR] = &ft_type_c;
	table[STR] = &ft_type_s;
	table[PTR] = &ft_type_ubase;
	table[D_INT] = &ft_type_d;
	table[I_INT] = &ft_type_d;
	table[U_INT] = &ft_type_ubase;
	table[LC_HEXA] = &ft_type_ubase;
	table[UC_HEXA] = &ft_type_ubase;
	table[PCT] = &ft_type_pct;
	return (table);
}

int	ft_conversion(const char **format, t_print **type_table, va_list args)
{
	t_tag	*tag;
	int		length;

	tag = ft_create_tag(format, args);
	if (!tag)
		return (MALLOC_ERROR);
	if (tag->type == NONE)
	{
		free(tag);
		return (TAG_BUILD_ERROR);
	}
	length = (*type_table[tag->type])(tag, args);
	free(tag);
	if (length < 0)
		return (length);
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_print	**type_table;
	int		length;
	int		c_length;

	length = 0;
	va_start(args, format);
	type_table = init_type_table();
	if (!type_table)
		return (MALLOC_ERROR);
	while (*format)
	{
		c_length = 1;
		if (*format == '%')
			c_length = ft_conversion(&format, type_table, args);
		else
			ft_putchar_fd(*format, 1);
		if (c_length < 0)
			return (c_length);
		length += c_length;
		format++;
	}
	va_end(args);
	free(type_table);
	return (length);
}
