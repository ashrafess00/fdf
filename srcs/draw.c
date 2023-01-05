/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:22:45 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 00:16:39 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	init_draw(t_mlx_data *my_mlx, t_points **points)
{
	int			i;
	int			points_arr[4][5];
	t_points	*current;

	i = -1;
	while (points[++i])
	{
		while (points[i] && points[i]->next && points[i]->next->bottom)
		{
			fill_points_arr(points_arr[0], points[i]);
			fill_points_arr(points_arr[1], points[i]->next);
			fill_points_arr(points_arr[2], points[i]->next->bottom);
			fill_points_arr(points_arr[3], points[i]->bottom);
			draw_from_p2p(my_mlx, points_arr[0], points_arr[1]);
			draw_from_p2p(my_mlx, points_arr[1], points_arr[2]);
			draw_from_p2p(my_mlx, points_arr[3], points_arr[2]);
			draw_from_p2p(my_mlx, points_arr[0], points_arr[3]);
			current = points[i];
			points[i] = points[i]->next;
			free(current);
		}
	}
}
