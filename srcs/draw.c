/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:22:45 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/31 21:59:35 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	fill_arr(int *arr, t_points *points)
{
	arr[0] = points->x;
	arr[1] = points->y;
	arr[2] = points->color;
}

void	init_draw(t_mlx_data *my_mlx, t_points **points)
{
	int			i;
	int			arr[4][3];
	t_points	*current;
	t_points	*current2;

	i = -1;
	while (points[++i])
	{
		while (points[i] && points[i]->next && points[i]->next->bottom)
		{
			fill_arr(arr[0], points[i]);
			fill_arr(arr[1], points[i]->next);
			fill_arr(arr[2], points[i]->next->bottom);
			fill_arr(arr[3], points[i]->bottom);
			draw_from_p2p(my_mlx, arr[0], arr[1], arr[1][2]);
			draw_from_p2p(my_mlx, arr[1], arr[2], arr[2][2]);
			draw_from_p2p(my_mlx, arr[3], arr[2], arr[2][2]);
			draw_from_p2p(my_mlx, arr[0], arr[3], arr[3][2]);
			current = points[i];
			points[i] = points[i]->next;
			free(current);
		}
	}
}
