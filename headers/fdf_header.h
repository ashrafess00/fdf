/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:57:14 by aessaoud          #+#    #+#             */
/*   Updated: 2022/12/31 21:46:31 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
#define FDF_HEADER_H
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
# define DEFAULT_Z 5
# define DEFAULT_S 1

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
	void		*mlx;
	void		*win;
	char		*addr;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			img_w;
	int			img_h;
	int			x_count;
	int			y_count;
	int			s;
	int			z;
	t_points	**points;
	char		**lines;
}	t_mlx_data;

void		print_node(t_points **points);
t_points	**get_coords(t_mlx_data *mlx_data, char **lines, int z, int s);
void		add_node(t_points **head, int x_y[2], char *num, int h);
int			get_lines_counts(char **line);
char		**read_file(t_mlx_data *mlx_data, int fd);
void		iso(int *x, int *y, int z, double degree);
void		init_draw(t_mlx_data *my_mlx, t_points **points);
void		intiate_window(t_mlx_data *my_mlx);
void		draw_from_p2p(t_mlx_data *my_mlx, int *fp, int *sp, int color);
int			win_size(int a);
void		write_error(char *s);
void		draw_me(t_mlx_data *my_mlx, int z, int s);
int			move(int key, t_mlx_data *my_mlx);
#endif