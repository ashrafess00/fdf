#include <math.h>
#include <stdio.h>
#include "fdf_header.h"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int	hi;
}	t_data;

int	handle_keypress(int keysym, t_data *data)
{
	printf("Keyrelease: %d\n", keysym);
	if (keysym == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	return (0);
}

int	handle_mouse(int mouse_click, t_data data)
{
	printf("mouse click->%d", mouse_click);
	return (0);
}

int	shalolo(t_data data)
{
	printf("shalolo");
	return (0);
}
int main()
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "hi window");
	
	mlx_hook(data.win_ptr, 4, 0L, &handle_keypress, &data);
	// mlx_loop_hook(data.mlx_ptr, &shalolo, &data);
	// mlx_key_hook(data.win_ptr, &handle_keypress, &data);
	// mlx_mouse_hook(data.win_ptr, &handle_mouse, &data);
	mlx_loop(data.mlx_ptr);
}