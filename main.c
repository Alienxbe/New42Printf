/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 20:34:49 by mykman            #+#    #+#             */
/*   Updated: 2021/07/27 22:02:28 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int main(void)
{
	int n[] = {125, 125, 125, -125, -125, -125, 356};
	int width[] = {10, 10, 10, 10, 10, 10, 10};
	int minsize[] = {0, 3, 5, 0, 3, 5, 15};
	for (int i = 0; i < 7; i++)
	{
		printf("Test %d:\n", i);
		printf("%-10s -> %d\n", "Original", printf("|%+*.*d|\n", width[i], minsize[i], n[i]));
		ft_printf("%-10s -> %d\n\n", "Yours", ft_printf("|%+*.*d|\n", width[i], minsize[i], n[i]));
	}
	return 0;
}
