/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:01:58 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 22:36:56 by aessaoud         ###   ########.fr       */
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

void	hex_to_rgb(int color_rgb[3], char *hex, int white)
{
	int	decimal;

	if (white == 1)
	{
		color_rgb[0] = 255;
		color_rgb[1] = 255;
		color_rgb[2] = 255;
	}
	else
	{
		decimal = hex_to_decimal(hex);
		color_rgb[0] = ((decimal >> 16) & 0xFF);
		color_rgb[1] = ((decimal >> 8) & 0xFF);
		color_rgb[2] = (decimal & 0xFF);
	}
}

static int	get_r_g_b(int color1, int color2, int dis, int i)
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

int	get_color(int *rgb1, int *rgb2, int dis, int i)
{
	int	r;
	int	g;
	int	b;

	r = get_r_g_b(rgb1[0], rgb2[0], dis, i);
	g = get_r_g_b(rgb1[1], rgb2[1], dis, i);
	b = get_r_g_b(rgb1[2], rgb2[2], dis, i);
	return (r << 16 | g << 8 | b);
}
