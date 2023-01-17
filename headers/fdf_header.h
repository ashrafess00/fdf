/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:57:14 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/17 15:57:34 by aessaoud         ###   ########.fr       */
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
# define DEFAULT_D 0.46373398
# define WITH_COLOR 0
# define WITH_WHITE 1
# define DEFAULT_T 0

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
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	int		dx;
	int		dy;
	int		rgb1;
	int		rgb2;
}	t_point__1_2;

typedef struct s__z_s_t
{
	int		z;
	int		s;
	int		t[2];
}	t__z_s_t;

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
	t__z_s_t		z_s_t;
}	t_mlx_data;

t_points_node	**get_coords(t_mlx_data *mlx_d);
void			add_node(t_points_node **head, char *num, int x_y[2],
					t__z_s_t z_s_t);
char			**read_file(t_mlx_data *mlx_data, int fd);
void			init_draw(t_mlx_data *my_mlx, t_points_node **points);
void			intiate_window(t_mlx_data *my_mlx);
void			draw_from_p2p(t_mlx_data *my_mlx, t_point__1_2 point__1_2);
int				win_size(int a);
void			write_error(char *s);
void			draw_me(t_mlx_data *my_mlx);
int				move(int key, t_mlx_data *my_mlx);
void			iso1(int *x, int *y, int z, double degree);
int				close_win(t_mlx_data *my_mlx);
int				hex_to_rgb(char *hex, int white);
int				get_color(int rgb1, int rgb2, int dis, int i);
void			draw_on_img(t_mlx_data *data, int x, int y, int color);
int				scroll(int key, int x, int y, t_mlx_data *my_mlx);
#endif