/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:34:32 by mykman            #+#    #+#             */
/*   Updated: 2021/07/27 21:40:03 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_size(int n, int minsize, int pos_sign_char)
{
	int	size;

	size = ft_intsize(n, 0);
	if (!n)
	{
		if (!minsize)
			size = 0;
		else
			size = 1;
	}
	if (size < minsize)
		size = minsize;
	if ((pos_sign_char && n >= 0) || (size == minsize && n < 0))
		size++;
	return (size);
}

char	*ft_printf_itoa(int n, int minsize, char pos_sign_char)
{
	char			*str;
	unsigned int	un;
	int				size;

	un = (unsigned int)n;
	size = get_size(n, minsize, pos_sign_char);
	str = (char *)ft_calloc(sizeof(char), size + 1);
	if (!str)
		return (NULL);
	str = ft_memset(str, '0', size);
	if (n < 0)
		un = -n;
	while (--size >= 0)
	{
		str[size] = '0' + un % 10;
		if (n < 0 && !size)
			str [size] = '-';
		else if (pos_sign_char && !size && n >= 0)
			str[size] = pos_sign_char;
		un /= 10;
	}
	return (str);
}
