/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:25:17 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/30 13:28:10 by aessaoud         ###   ########.fr       */
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

static void	bresenham_algo_d_0(t_mlx_data *my_mlx, int *po, int color, int d)
{
	int	pk;
	int	i;

	pk = 2 * po[5] - po[4];
	i = -1;
	while (++i <= po[4])
	{
		set_dir(&po[0], po[2]);
		if (pk < 0)
		{
			draw_on_img(my_mlx, po[0], po[1], color);
			pk = pk + 2 * po[5];
		}
		else
		{
			set_dir(&po[1], po[3]);
			draw_on_img(my_mlx, po[0], po[1], color);
			pk = pk + 2 * po[5] - 2 * po[4];
		}
	}
}

static void	bresenham_algo_d_1(t_mlx_data *my_mlx, int *po, int color, int d)
{
	int	pk;
	int	i;

	pk = 2 * po[5] - po[4];
	i = -1;
	while (++i <= po[4])
	{
		set_dir(&po[0], po[2]);
		if (pk < 0)
		{
			draw_on_img(my_mlx, po[1], po[0], color);
			pk = pk + 2 * po[5];
		}
		else
		{
			set_dir(&po[1], po[3]);
			draw_on_img(my_mlx, po[1], po[0], color);
			pk = pk + 2 * po[5] - 2 * po[4];
		}
	}
}

/*
indexes:
	0 -> x1
	1 -> y1
	2 -> x2
	3 -> y2
	4 -> dx
	5 -> dy
	6 -> color
*/
void	draw_from_p2p(t_mlx_data *my_mlx, int *fp, int *sp, int color)
{
	int	infos[7];

	infos[0] = fp[0];
	infos[1] = fp[1];
	infos[2] = sp[0];
	infos[3] = sp[1];
	infos[4] = abs(sp[0] - fp[0]);
	infos[5] = abs(sp[1] - fp[1]);
	infos[6] = sp[2];
	if (infos[4] > infos[5])
	{
		bresenham_algo_d_0(my_mlx, infos, color, 0);
		return ;
	}
	infos[0] = fp[1];
	infos[1] = fp[0];
	infos[2] = sp[1];
	infos[3] = sp[0];
	infos[4] = abs(sp[1] - fp[1]);
	infos[5] = abs(sp[0] - fp[0]);
	bresenham_algo_d_1(my_mlx, infos, color, 1);
}
