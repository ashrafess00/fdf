/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:01:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/05 21:21:11 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int	rgb_to_decimal( int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

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

void	hex_to_rgb(int color_rgb[3], char *hex, int white)
{
	if (white == 1)
	{
		color_rgb[0] = hex_to_decimal("ff");
		color_rgb[1] = hex_to_decimal("ff");
		color_rgb[2] = hex_to_decimal("ff");
	}
	else
	{
		color_rgb[0] = hex_to_decimal(ft_substr(hex, 2, 2));
		color_rgb[1] = hex_to_decimal(ft_substr(hex, 4, 2));
		color_rgb[2] = hex_to_decimal(ft_substr(hex, 6, 2));
	}
}

int	get_color(int *rgb1, int *rgb2, int dis, int i)
{
	int r;
	int g;
	int b;
	float	range;
	int	r1;
	int	r2;
	int distance;
	float	fac;
	
	distance = dis;
	r1 = rgb1[0];
	r2 = rgb2[0];
	range = abs(r2 - r1);
	fac = range / distance;
	if (r1 <= r2)
		r = (int)(r1 + (i * fac));
	else
		r = (int)(r1 - (i * fac));
	r1 = rgb1[1];
	r2 = rgb2[1];
	range = abs(r2 - r1);
	fac = range / distance;
	if (r1 <= r2)
		g = (int)(r1 + (i * fac));
	else
		g = (int)(r1 - (i * fac));
	r1 = rgb1[2];
	r2 = rgb2[2];
	range = abs(r2 - r1);
	fac = range / distance;
	if (r1 <= r2)
		b = (int)(r1 + (i * fac));
	else
		b = (int)(r1 - (i * fac));
	return (rgb_to_decimal(r, g, b));
}