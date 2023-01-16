/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:17 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/09 22:33:26 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static int	get_steps(int dx, int dy)
{
	if (dx > dy)
		return (dx);
	else
		return (dy);
}

void	draw_from_p2p(t_mlx_data *mlx, t_point__1_2 point__1_2)
{
	int		color;
	float	incx;
	float	incy;
	int		steps;
	int		i;

	steps = get_steps(point__1_2.dx, point__1_2.dy);
	incx = point__1_2.dx / (float) steps;
	incy = point__1_2.dy / (float) steps;
	i = -1;
	while (++i <= steps)
	{
		if (point__1_2.x1 < point__1_2.x2)
			point__1_2.x1 += incx;
		else
			point__1_2.x1 -= incx;
		if (point__1_2.y1 < point__1_2.y2)
			point__1_2.y1 += incy;
		else
			point__1_2.y1 -= incy;
		color = get_color(point__1_2.rgb1, point__1_2.rgb2, steps, i);
		draw_on_img(mlx, (int)round(point__1_2.x1), (int)round(point__1_2.y1),
			color);
	}
}
