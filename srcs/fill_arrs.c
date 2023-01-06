/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arrs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:06:18 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/06 19:47:15 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"
/*
indexes:
	0 -> x1
	1 -> y1
	2 -> x2
	3 -> y2
	4 -> dx
	5 -> dy
	6 -> r
	7 -> g
	8 -> b
*/

void	fill_points_arr(int *points_arr, t_points_node *points)
{
	points_arr[0] = points->x;
	points_arr[1] = points->y;
	points_arr[2] = points->color_rgb[0];
	points_arr[3] = points->color_rgb[1];
	points_arr[4] = points->color_rgb[2];
}

void	fill_info_arr(int *infos, int *fp, int *sp)
{
	infos[0] = fp[0];
	infos[1] = fp[1];
	infos[2] = sp[0];
	infos[3] = sp[1];
	infos[4] = abs(sp[0] - fp[0]);
	infos[5] = abs(sp[1] - fp[1]);
}

void	fill_color_arr(int *rgb1, int *rgb2, int *fp, int *sp)
{
	rgb1[0] = fp[2];
	rgb1[1] = fp[3];
	rgb1[2] = fp[4];
	rgb2[0] = sp[2];
	rgb2[1] = sp[3];
	rgb2[2] = sp[4];
}
