/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:22:45 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 22:39:55 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	fill_point(t_point__1_2 *point__1_2, t_points_node *point1,
t_points_node *point2)
{
	point__1_2->x1 = point1->x;
	point__1_2->y1 = point1->y;
	point__1_2->rgb1[0] = point1->color_rgb[0];
	point__1_2->rgb1[1] = point1->color_rgb[1];
	point__1_2->rgb1[2] = point1->color_rgb[2];
	point__1_2->x2 = point2->x;
	point__1_2->y2 = point2->y;
	point__1_2->rgb2[0] = point2->color_rgb[0];
	point__1_2->rgb2[1] = point2->color_rgb[1];
	point__1_2->rgb2[2] = point2->color_rgb[2];
	point__1_2->dx = abs(point2->x - point1->x);
	point__1_2->dy = abs(point2->y - point1->y);
}

void	init_draw(t_mlx_data *my_mlx, t_points_node **points)
{
	int				i;
	t_points_node	*current;
	t_point__1_2	point__1_2;

	i = -1;
	while (points[++i])
	{
		while (points[i] && points[i]->next && points[i]->next->bottom)
		{
			fill_point(&point__1_2, points[i], points[i]->next);
			draw_from_p2p(my_mlx, point__1_2);
			fill_point(&point__1_2, points[i]->next, points[i]->next->bottom);
			draw_from_p2p(my_mlx, point__1_2);
			fill_point(&point__1_2, points[i]->bottom, points[i]->next->bottom);
			draw_from_p2p(my_mlx, point__1_2);
			fill_point(&point__1_2, points[i], points[i]->bottom);
			draw_from_p2p(my_mlx, point__1_2);
			current = points[i];
			points[i] = points[i]->next;
			free(current);
		}
	}
}
