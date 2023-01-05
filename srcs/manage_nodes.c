/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:00:42 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/05 20:16:01 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static t_points	*create_node(int x, int y, int z, int color_rgb[3])
{
	t_points	*new_node;

	new_node = (struct s_points *) ft_calloc(1, sizeof (struct s_points));
	if (!new_node)
		return (0);
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->color_rgb[0] = color_rgb[0];
	new_node->color_rgb[1] = color_rgb[1];
	new_node->color_rgb[2] = color_rgb[2];
	new_node->next = NULL;
	return (new_node);
}

void	add_node(t_points **head, char *num, int x_y_z[4], float d)
{
	t_points	*temp;
	int			color_rgb[3];
	int			splitted_z;	
	char		**num_splitted;

	num_splitted = ft_split(ft_strdup(num), ',');
	splitted_z = ft_atoi(num_splitted[0]) * x_y_z[2];
	iso (&x_y_z[0], &x_y_z[1], splitted_z, d);
	if (ft_strchr(num, ','))
		hex_to_rgb(color_rgb, ft_strchr(num, ',')+1, WITH_COLOR);
	else
		hex_to_rgb(color_rgb, NULL, WITH_WHITE);
	if (*head == NULL)
		*head = create_node(x_y_z[0], x_y_z[1], splitted_z, color_rgb);
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_node(x_y_z[0], x_y_z[1], splitted_z, color_rgb);
	}
	free_arr(num_splitted);
	free(num);
}
