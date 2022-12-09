/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:57:14 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/08 20:25:01 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
#define FDF_HEADER_H
#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_points
{
	int	x;
	int	y;
	int z;
	int color;
	struct s_points *next;
	struct s_points *bottom;
}	t_points;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
	int		x_count;
	int		y_count;
}	t_mlx_data;

void		print_node(t_points **points);
t_points	**get_coords(t_mlx_data mlx_data, char **lines);
void	add_node(t_points **head, int x, int y, char *num);
// t_points	*create_node(int x, int y, int z);
int			get_lines_counts(char **line);
char		**read_file(t_mlx_data *mlx_data, int fd);
void		draw_line(t_mlx_data my_mlx, int x1, int y1, int x2, int y2, int color);
void		iso(int *x, int *y, int z, double degree);
void		iso_linked(t_points * tmp);
void		int_draw(t_mlx_data my_mlx, t_points **points);
#endif