/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_header.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessaoud <aessaoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:57:14 by aessaoud          #+#    #+#             */
/*   Updated: 2023/01/05 21:22:14 by aessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEADER_H
# define FDF_HEADER_H
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# define DEFAULT_Z 3
# define DEFAULT_S 1
# define DEFAULT_D 0.5
# define WITH_COLOR 0
# define WITH_WHITE 1
typedef struct s_points
{
	int				x;
	int				y;
	int				z;
	int				color;
	struct s_points	*next;
	struct s_points	*bottom;
	int				color_rgb[3];
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
	t_points	**points;
	char		**lines;
}	t_mlx_data;

t_points	**get_coords(t_mlx_data *mlx_data, int z, int s, float d);
void		add_node(t_points **head, char *num, int x_y_z[4], float d);
char		**read_file(t_mlx_data *mlx_data, int fd);
void		iso(int *x, int *y, int z, double degree);
void		init_draw(t_mlx_data *my_mlx, t_points **points);
void		intiate_window(t_mlx_data *my_mlx);
void		draw_from_p2p(t_mlx_data *my_mlx, int *fp, int *sp, int *color1, int *color2);
int			win_size(int a);
void		write_error(char *s);
void		draw_me(t_mlx_data *my_mlx, int z, int s, float d);
int			move(int key, t_mlx_data *my_mlx);
void		iso(int *x, int *y, int z, double degree);
int			close_win(t_mlx_data *my_mlx);
void		hex_to_rgb(int color_rgb[3], char *hex, int white);
int			rgb_to_decimal( int r, int g, int b);
int			get_color(int *rgb1, int *rgb2, int dis, int i);
#endif