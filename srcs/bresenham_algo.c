/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:17 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 00:06:58 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	draw_on_img(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= data->img_w || y >= data->img_h)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

static void	set_dir(int *po1, int po2)
{
	if (*po1 < po2)
		(*po1)++;
	else
		(*po1)--;
}

static void	bresenham_algo_d_0(t_mlx_data *mlx, int *po, int *rgb1, int *rgb2)
{
	int	pk;
	int	i;
	int	color;

	pk = 2 * po[5] - po[4];
	i = -1;
	while (++i <= po[4])
	{
		color = get_color(rgb1, rgb2, po[4], i);
		set_dir(&po[0], po[2]);
		if (pk < 0)
		{
			draw_on_img(mlx, po[0], po[1], color);
			pk = pk + 2 * po[5];
		}
		else
		{
			set_dir(&po[1], po[3]);
			draw_on_img(mlx, po[0], po[1], color);
			pk = pk + 2 * po[5] - 2 * po[4];
		}
	}
}

static void	bresenham_algo_d_1(t_mlx_data *mlx, int *po, int *rgb1, int *rgb2)
{
	int	pk;
	int	i;
	int	color;

	pk = 2 * po[5] - po[4];
	i = -1;
	while (++i <= po[4])
	{
		color = get_color(rgb1, rgb2, po[4], i);
		set_dir(&po[0], po[2]);
		if (pk < 0)
		{
			draw_on_img(mlx, po[1], po[0], color);
			pk = pk + 2 * po[5];
		}
		else
		{
			set_dir(&po[1], po[3]);
			draw_on_img(mlx, po[1], po[0], color);
			pk = pk + 2 * po[5] - 2 * po[4];
		}
	}
}

void	draw_from_p2p(t_mlx_data *my_mlx, int *fp, int *sp)
{
	int	infos[7];
	int	rgb1[3];
	int	rgb2[3];

	fill_info_arr(infos, fp, sp);
	fill_color_arr(rgb1, rgb2, fp, sp);
	if (infos[4] > infos[5])
	{
		bresenham_algo_d_0(my_mlx, infos, rgb1, rgb2);
		return ;
	}
	infos[0] = fp[1];
	infos[1] = fp[0];
	infos[2] = sp[1];
	infos[3] = sp[0];
	infos[4] = abs(sp[1] - fp[1]);
	infos[5] = abs(sp[0] - fp[0]);
	bresenham_algo_d_1(my_mlx, infos, rgb1, rgb2);
}
