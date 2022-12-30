/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:10:18 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/30 18:18:17 by aessaoud         ###   ########.fr       */
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

void	draw_me(t_mlx_data *my_mlx)
{
	init_draw(my_mlx, my_mlx->points);
	free_points(my_mlx->points);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->win, my_mlx->img,
		(win_size(my_mlx->img_w) - my_mlx->img_w) / 2,
		(win_size(my_mlx->img_h) - my_mlx->img_h) / 2);
	
}