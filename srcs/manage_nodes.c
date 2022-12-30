/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 18:00:42 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/30 15:16:33 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_header.h"

//isometric projection
void	iso(int *x, int *y, int z, double degree)
{
	int	p_x;
	int	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(degree);
	*y = -z + (p_x + p_y) * sin(degree);
}

int	hex_to_color(char *hex)
{
	int	i;
	int	r;

	i = -1;
	r = 0;
	while (hex[++i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			r = (r * 16) + (hex[i] - '0');
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			r = (r * 16) + (hex[i] - 'A' + 10);
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			r = (r * 16) + (hex[i] - 'a' + 10);
	}
	return (r);
}

t_points	*create_node(int x, int y, int z, int color)
{
	t_points	*new_node;

	new_node = (struct s_points *) ft_calloc(1, sizeof (struct s_points));
	if (!new_node)
		return (0);
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->color = color;
	new_node->next = NULL;
	return (new_node);
}

static void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	add_node(t_points **head, int x_y[2], char *num, char *h)
{
	t_points	*temp;
	int			color;
	int			z;	
	char		**num_splitted;

	num_splitted = ft_split(ft_strdup(num), ',');
	z = ft_atoi(num_splitted[0]) * ft_atoi(h);
	iso (&x_y[0], &x_y[1], z, 0.5);
	if (ft_strchr(num, ','))
		color = hex_to_color(ft_strchr(num, ','));
	else
		color = 0xffffff;
	if (*head == NULL)
		*head = create_node(x_y[0], x_y[1], z, color);
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = create_node(x_y[0], x_y[1], z, color);
	}
	free_arr(num_splitted);
	free(num);
}
