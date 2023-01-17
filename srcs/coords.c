/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:54:26 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/17 15:57:34 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

void	link_to_down_nodes(t_points_node **points)
{
	t_points_node	*tmp1;
	t_points_node	*tmp2;
	int				i;

	i = -1;
	while (points[++i] && points[i + 1])
	{
		tmp1 = points[i];
		tmp2 = points[i + 1];
		while (tmp1 != NULL)
		{
			tmp1->bottom = tmp2;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
}

t_points_node	**get_coords(t_mlx_data *mlx)
{
	t_points_node	**points;
	char			**line;
	int				i;
	int				j;
	int				x_y[2];

	points = ft_calloc(mlx->y_count + 1, sizeof(t_points_node *));
	i = -1;
	while (++i < mlx->y_count)
	{
		j = -1;
		line = ft_split(ft_strdup(mlx->lines[i]), ' ');
		if (!line)
			write_error("an error occured :(\n");
		while (line[++j])
		{
			x_y[0] = (((mlx->img_w + mlx->z_s_t.s)
						/ mlx->x_count) * j + mlx->img_w / 2);
			x_y[1] = ((mlx->img_h + mlx->z_s_t.s) / mlx->y_count * i);
			add_node(&points[i], line[j], x_y, mlx->z_s_t);
		}
		free(line);
	}
	link_to_down_nodes(points);
	return (points);
}
