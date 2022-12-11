/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:54:26 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/08 20:24:54 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "./mlx/mlx.h"
#include "fdf_header.h"

t_points	*create_node(int x, int y, int z, int color)
{
	t_points	*new_node;
	new_node = (struct s_points*) ft_calloc(1, sizeof (struct s_points));

	if (!new_node)
		return (0);
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->color = color;
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_points **head, int x, int y, char *num)
{
	t_points	*temp;
	int color;
	int	z;
	
	z = ft_atoi(ft_split(num, ',')[0]) * 3;
	iso (&x, &y, z, 0.5);
	if (ft_split(num, ',')[1])
		color = ft_atoi(ft_split(num, ',')[1]);
	else
		color = 0xffffff;
	if (*head == NULL)
		*head = create_node(x, y, z, color);
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_node(x, y, z, color);
	}
}

void	link_to_down_nodes(t_points **points)
{
	t_points	*tmp1;
	t_points	*tmp2;
	int			i;

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

t_points	**get_coords(t_mlx_data mlx_data, char **lines)
{
	t_points	**points;
	char		**line;
	int			i;
	int			j;
	int			coords_with_iso[2];
	points = ft_calloc(mlx_data.y_count + 1, sizeof(t_points *));
	i = -1;
	while (++i < mlx_data.y_count)
	{
		j = -1;
		line = ft_split(lines[i], ' ');
		points[i] = NULL;
		while (line[++j])
			add_node(&points[i], ((mlx_data.img_w - 100) / mlx_data.x_count) * j + 300,
				((mlx_data.img_h - 100) / mlx_data.y_count) * i, line[j]);
		free (line);
	}
	link_to_down_nodes(points);
	return (points);
}



