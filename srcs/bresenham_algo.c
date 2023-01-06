/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:17 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 22:45:38 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	set_dir(int *po1, int po2)
{
	if (*po1 < po2)
		(*po1)++;
	else
		(*po1)--;
}

static void	draw_with_decide(t_mlx_data *mlx, t_point__1_2 point__1_2,
int color, int d)
{
	if (d == 0)
		draw_on_img(mlx, point__1_2.x1, point__1_2.y1, color);
	else
		draw_on_img(mlx, point__1_2.y1, point__1_2.x1, color);
}

static void	bresenham_algo(t_mlx_data *mlx, t_point__1_2 point__1_2, int d)
{
	int	pk;
	int	i;
	int	color;

	pk = 2 * point__1_2.dy - point__1_2.dx;
	i = -1;
	while (++i <= point__1_2.dx)
	{
		color = get_color(point__1_2.rgb1, point__1_2.rgb2, point__1_2.dx, i);
		set_dir(&point__1_2.x1, point__1_2.x2);
		if (pk < 0)
		{
			draw_with_decide(mlx, point__1_2, color, d);
			pk = pk + 2 * point__1_2.dy;
		}
		else
		{
			set_dir(&point__1_2.y1, point__1_2.y2);
			draw_with_decide(mlx, point__1_2, color, d);
			pk = pk + 2 * point__1_2.dy - 2 * point__1_2.dx;
		}
	}
}

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	draw_from_p2p(t_mlx_data *my_mlx, t_point__1_2 point__1_2)
{
	if (point__1_2.dx > point__1_2.dy)
		bresenham_algo(my_mlx, point__1_2, 0);
	else
	{
		swap(&point__1_2.x1, &point__1_2.y1);
		swap(&point__1_2.x2, &point__1_2.y2);
		swap(&point__1_2.dx, &point__1_2.dy);
		bresenham_algo(my_mlx, point__1_2, 1);
	}
}
