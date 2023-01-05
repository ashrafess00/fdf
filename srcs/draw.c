/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:22:45 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/05 20:06:51 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	fill_arr(int *arr, t_points *points)
{
	arr[0] = points->x;
	arr[1] = points->y;
	
}

void	fill_color(int *arr, t_points *points)
{
	arr[0] = points->color_rgb[0];
	arr[1] = points->color_rgb[1];
	arr[2] = points->color_rgb[2];
}

void	init_draw(t_mlx_data *my_mlx, t_points **points)
{
	int			i;
	int			arr[4][2];
	int			colors_rgb[4][3];
	t_points	*current;
	t_points	*current2;

	i = -1;
	while (points[++i])
	{
		while (points[i] && points[i]->next && points[i]->next->bottom)
		{
			fill_arr(arr[0], points[i]);
			fill_color(colors_rgb[0], points[i]);
			
			fill_arr(arr[1], points[i]->next);
			fill_color(colors_rgb[1], points[i]->next);

			fill_arr(arr[2], points[i]->next->bottom);
			fill_color(colors_rgb[2], points[i]->next->bottom);

			fill_arr(arr[3], points[i]->bottom);
			fill_color(colors_rgb[3], points[i]->bottom);

			draw_from_p2p(my_mlx, arr[0], arr[1], colors_rgb[0], colors_rgb[1]);
			draw_from_p2p(my_mlx, arr[1], arr[2], colors_rgb[1], colors_rgb[2]);
			draw_from_p2p(my_mlx, arr[3], arr[2], colors_rgb[3], colors_rgb[2]);
			draw_from_p2p(my_mlx, arr[0], arr[3], colors_rgb[0], colors_rgb[3]);
			current = points[i];
			points[i] = points[i]->next;
			free(current);
		}
	}
}
