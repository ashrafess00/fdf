/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:10:18 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/02 16:22:26 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	free_points(t_points **points)
{
	int			i;
	t_points	*tmp;

	i = -1;
	while (points[++i])
	{
		while (points[i])
		{
			tmp = points[i];
			points[i] = points[i]->next;
			free(tmp);
		}
	}
	free(points);
}

void	draw_me(t_mlx_data *my_mlx, int z, int s, float d)
{
	my_mlx->points = get_coords(my_mlx, z, s, d);
	init_draw(my_mlx, my_mlx->points);
	free_points(my_mlx->points);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, my_mlx->img,
		(win_size(my_mlx->img_w) - my_mlx->img_w) / 2,
		(win_size(my_mlx->img_h) - my_mlx->img_h) / 2);
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 10, 0x810202,
		"click arrow up to increase attitude");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 30, 0x810202,
		"click arrow down to decrease attitude");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 50, 0x810202,
		"click arrow right to increase size");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 70, 0x810202,
		"click arrow left to decrease size");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 90, 0x810202,
		"click + to increase degree");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 110, 0x810202,
		"click - to decrease degree");
}
