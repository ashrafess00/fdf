/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:01:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/12 18:31:51 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

static int	hex_to_decimal(char *hex)
{
	int	i;
	int	r;

	i = -1;
	r = 0;
	while (hex[++i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			r = (r * 16) + (hex[i] - '0');
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			r = (r * 16) + (hex[i] - 'A' + 10);
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			r = (r * 16) + (hex[i] - 'a' + 10);
	}
	return (r);
}

int	hex_to_rgb(char *hex, int white)
{
	int	decimal;

	if (white == 1)
		return (16777215);
	decimal = hex_to_decimal(hex);
	return (decimal);
}

static int	change_gradiant(int color1, int color2, int dis, int i)
{
	float	range;
	float	fac;

	range = abs(color2 - color1);
	fac = range / dis;
	if (color1 <= color2)
		return ((int)(color1 + (i * fac)));
	else
		return ((int)(color1 - (i * fac)));
}

int	get_color(int rgb1, int rgb2, int dis, int i)
{
	int	r;
	int	g;
	int	b;

	r = change_gradiant((rgb1 >> 16) & 0xFF, (rgb2 >> 16) & 0xFF, dis, i);
	g = change_gradiant((rgb1 >> 8) & 0xFF, (rgb2 >> 8) & 0xFF, dis, i);
	b = change_gradiant(rgb1 & 0xFF, rgb2 & 0xFF, dis, i);
	return (r << 16 | g << 8 | b);
}
