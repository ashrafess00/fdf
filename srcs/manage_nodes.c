/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:00:42 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/16 15:34:16 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

static void	free_arr(char **arr, char *num)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
	free(num);
}

static t_points_node	*create_node(int x, int y, int z, int color_rgb)
{
	t_points_node	*new_node;

	new_node = (struct s_points_node *) ft_calloc(1,
			sizeof (struct s_points_node));
	if (!new_node)
		return (0);
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->color_rgb = color_rgb;
	new_node->next = NULL;
	return (new_node);
}

static void	fill_colour(int *color_rgb, char *num)
{
	if (ft_strchr(num, ','))
		*color_rgb = hex_to_rgb(ft_strchr(num, ',') + 1, WITH_COLOR);
	else
		*color_rgb = hex_to_rgb(NULL, WITH_WHITE);
}

void	add_node(t_points_node **head, char *num, int x_y[2],
t__z_s_i_d z_s_i_d)
{
	t_points_node	*temp;
	int				color_rgb;
	int				splitted_z;	
	char			**num_splitted;

	num_splitted = ft_split(ft_strdup(num), ',');
	splitted_z = ft_atoi(num_splitted[0]) * z_s_i_d.z;
	iso1 (&x_y[0], &x_y[1], splitted_z, DEFAULT_D);
	x_y[0] += z_s_i_d.t[0];
	x_y[1] += z_s_i_d.t[1];
	fill_colour(&color_rgb, num);
	if (*head == NULL)
		*head = create_node(x_y[0], x_y[1], splitted_z, color_rgb);
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_node(x_y[0], x_y[1], splitted_z, color_rgb);
		if (!temp->next)
			write_error("an error occured :(\n");
	}
	free_arr(num_splitted, num);
}
