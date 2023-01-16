/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:10:18 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/16 15:19:37 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	free_points(t_points_node **points)
{
	int				i;
	t_points_node	*tmp;

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

void	draw_me(t_mlx_data *my_mlx)
{
	my_mlx->points = get_coords(my_mlx);
	init_draw(my_mlx, my_mlx->points);
	free_points(my_mlx->points);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, my_mlx->img,
		(win_size(my_mlx->img_w) - my_mlx->img_w) / 2,
		(win_size(my_mlx->img_h) - my_mlx->img_h) / 2);
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 10, 0xffbb00,
		"click [+] to increase attitude");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 30, 0xffbb00,
		"click [-] down to decrease attitude");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 50, 0xffbb00,
		"[scrol up] to zoom in");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 70, 0xffbb00,
		"[scrol down] to zoom out");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 90, 0xffbb00,
		"click [key up] to translate up");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 110, 0xffbb00,
		"click [key down] to translate down");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 130, 0xffbb00,
		"click [key right] to translate right");
	mlx_string_put(my_mlx->mlx, my_mlx->win, 10, 150, 0xffbb00,
		"click [key left] to translate left");
}
