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

// static void	bresenham_algo(t_mlx_data my_mlx, int x1, int y1, int x2, int y2, int dx, int dy, int d)
// {
// 	int pk = 2 * dy - dx;
// 	int	i;

// 	i = -1;
// 	while (++i <= dx)
// 	{
// 		x1 < x2 ? x1++ : x1--;
// 		if (pk < 0)
// 		{
// 			if (d == 0)
// 				custome_pixel_put(&my_mlx, x1, y1, 0xfcba03);
// 			else
// 				custome_pixel_put(&my_mlx, y1, x1, 0xfcba03);
// 			pk = pk + 2 * dy;
// 		}
// 		else
// 		{
// 			y1 < y2 ? y1++ : y1--;
// 			if (d == 0)
// 				custome_pixel_put(&my_mlx, x1, y1, 0xfcba03);
// 			else
// 				custome_pixel_put(&my_mlx, y1, x1, 0xfcba03);
// 			pk = pk + 2 * dy - 2 * dx;
// 		}
// 	}
// }

static void	bresenham_algo(t_mlx_data my_mlx, int *po, int color, int d)
{
	int pk = 2 * po[5] - po[4];
	int	i;

	i = -1;
	while (++i <= po[4])
	{
		po[0] < po[2] ? po[0]++ : po[0]--;
		if (pk < 0)
		{
			if (d == 0)
				custome_pixel_put(&my_mlx, po[0], po[1], color);
			else
				custome_pixel_put(&my_mlx, po[1], po[0], color);
			pk = pk + 2 * po[5];
		}
		else
		{
			po[1] < po[3] ? po[1]++ : po[1]--;
			if (d == 0)
				custome_pixel_put(&my_mlx, po[0], po[1], color);
			else
				custome_pixel_put(&my_mlx, po[1], po[0], color);
			pk = pk + 2 * po[5] - 2 * po[4];
		}
	}
}

void	draw_from_p2p(t_mlx_data my_mlx, int *fp, int *sp, int color)
{
	int infos[7];

	infos[0] = fp[0];//x1
	infos[1] = fp[1];//y1
	infos[2] = sp[0];//x2
	infos[3] = sp[1];//y2
	infos[4] = abs(sp[0] - fp[0]);
	infos[5] = abs(sp[1] - fp[1]);
	infos[6] = sp[2];
	if (infos[4] > infos[5])
	{
		bresenham_algo(my_mlx, infos, color, 0);
		return ;
	}
	infos[0] = fp[1];//x1
	infos[1] = fp[0];//y1
	infos[2] = sp[1];//x2d
	infos[3] = sp[0];//y2
	infos[4] = abs(sp[1] - fp[1]);
	infos[5] = abs(sp[0] - fp[0]);
	bresenham_algo(my_mlx, infos, color, 1);
}

static void	init_and_draw(t_mlx_data my_mlx, int arr[4][3])
{
	draw_from_p2p(my_mlx, arr[0], arr[1], arr[1][2]);
	draw_from_p2p(my_mlx, arr[1], arr[2], arr[2][2]);
	draw_from_p2p(my_mlx, arr[3], arr[2], arr[2][2]);
	draw_from_p2p(my_mlx, arr[0], arr[3], arr[3][2]);
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
