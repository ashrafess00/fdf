/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:57:14 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/09 12:55:12 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <fcntl.h>
# define DEFAULT_Z 3
# define DEFAULT_S 1
# define DEFAULT_D 0.5
# define WITH_COLOR 0
# define WITH_WHITE 1
# define DEFAULT_I 1

typedef struct s_points_node
{
	int						x;
	int						y;
	int						z;
	int						color;
	struct s_points_node	*next;
	struct s_points_node	*bottom;
	int						color_rgb;
}	t_points_node;

typedef struct s_point__1_2
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dx;
	int	dy;
	int	rgb1;
	int	rgb2;
}	t_point__1_2;

typedef struct s__z_s_i_d
{
	int		z;
	int		s;
	int		i;
	float	d;
}	t__z_s_i_d;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*win;
	char			*addr;
	void			*img;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				img_w;
	int				img_h;
	int				x_count;
	int				y_count;
	t_points_node	**points;
	char			**lines;
	t__z_s_i_d		z_s_i_d;
}	t_mlx_data;

t_points_node	**get_coords(t_mlx_data *mlx_d);
void			add_node(t_points_node **head, char *num, int x_y[2],
					t__z_s_i_d z_s_i_d);
char			**read_file(t_mlx_data *mlx_data, int fd);
void			init_draw(t_mlx_data *my_mlx, t_points_node **points);
void			intiate_window(t_mlx_data *my_mlx);
void			draw_from_p2p(t_mlx_data *my_mlx, t_point__1_2 point__1_2);
int				win_size(int a);
void			write_error(char *s);
void			draw_me(t_mlx_data *my_mlx);
int				move(int key, t_mlx_data *my_mlx);
void			iso1(int *x, int *y, int z, double degree);
void			iso2(int *x, int *y, int z);
int				close_win(t_mlx_data *my_mlx);
int				hex_to_rgb(char *hex, int white);
int				get_color(int rgb1, int rgb2, int dis, int i);
void			draw_on_img(t_mlx_data *data, int x, int y, int color);
#endif