/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:22:45 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/09 11:42:09 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

//isometric projection
void	iso(int *x, int *y, int z, double degree)
{
	int	p_x;
	int	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(degree);
	*y = -z + (p_x + p_y) * sin(degree);
}

void	custome_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > data->img_w || y > data->img_h)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	bresenham_algo(t_mlx_data my_mlx, int x1, int y1, int x2, int y2, int dx, int dy, int d)
{
	int pk = 2 * dy - dx;
	int	i;

	i = -1;
	while (++i <= dx)
	{
		x1 < x2 ? x1++ : x1--;
		if (pk < 0)
		{
			if (d == 0)
				custome_pixel_put(&my_mlx, x1, y1, 0xfcba03);
			else
				custome_pixel_put(&my_mlx, y1, x1, 0xfcba03);
			pk = pk + 2 * dy;
		}
		else
		{
			y1 < y2 ? y1++ : y1--;
			if (d == 0)
				custome_pixel_put(&my_mlx, x1, y1, 0xfcba03);
			else
				custome_pixel_put(&my_mlx, y1, x1, 0xfcba03);
			pk = pk + 2 * dy - 2 * dx;
		}
	}
}

void	draw_from_p2p(t_mlx_data my_mlx, int *fp, int *sp, int color)
{
	int	i;
	int	coordinates[5];
	int	dx;
	int	dy;
	int	points[4];
	double degree = 0.5;

	dx = abs(sp[0] - fp[0]);
	dy = abs(sp[1] - fp[1]);
	if (dx > dy)
		bresenham_algo(my_mlx, fp[0], fp[1], sp[0], sp[1], dx, dy, 0);
	else
		bresenham_algo(my_mlx, fp[1], fp[0], sp[1], sp[0], dy, dx, 1);
}

static void	init_and_draw(t_mlx_data my_mlx, int arr[4][3])
{
	// iso (&arr[0][0], &arr[0][1], arr[0][2], 0.5);
	// iso (&arr[1][0], &arr[1][1], arr[1][2], 0.5);
	// iso (&arr[2][0], &arr[2][1], arr[2][2], 0.5);
	// iso (&arr[3][0], &arr[3][1], arr[3][2], 0.5);
	draw_from_p2p(my_mlx, arr[0], arr[1], 0xf5bf42);
	draw_from_p2p(my_mlx, arr[1], arr[2], 0xf5bf42);
	draw_from_p2p(my_mlx, arr[3], arr[2], 0xf5bf42);
	draw_from_p2p(my_mlx, arr[0], arr[3], 0xf5bf42);
}

void	init_draw(t_mlx_data my_mlx, t_points **points)
{
	int	i;
	int arr[4][3];
	
	i = -1;
	while (points[++i])
	{
		while (points[i] && points[i]->next && points[i]->next->bottom)
		{
			// arr[0][0] = points[i]->x;
			// arr[0][1] = points[i]->y;
			// arr[0][2] = points[i]->z;
			// arr[1][0] = points[i]->next->x;
			// arr[1][1] = points[i]->next->y;
			// arr[1][2] = points[i]->next->z;
			// arr[2][0] = points[i]->next->bottom->x;
			// arr[2][1] = points[i]->next->bottom->y;
			// arr[2][2] = points[i]->next->bottom->z;
			// arr[3][0] = points[i]->bottom->x;
			// arr[3][1] = points[i]->bottom->y;
			// arr[3][2] = points[i]->bottom->z;

			arr[0][0] = points[i]->x;
			arr[0][1] = points[i]->y;
			arr[0][2] = points[i]->color;

			arr[1][0] = points[i]->next->x;
			arr[1][1] = points[i]->next->y;
			arr[1][2] = points[i]->next->color;

			arr[2][0] = points[i]->next->bottom->x;
			arr[2][1] = points[i]->next->bottom->y;
			arr[2][2] = points[i]->next->bottom->color;

			arr[3][0] = points[i]->bottom->x;
			arr[3][1] = points[i]->bottom->y;
			arr[3][2] = points[i]->bottom->color;
			init_and_draw (my_mlx, arr);
			points[i] = points[i]->next;
		}
	}	
}
