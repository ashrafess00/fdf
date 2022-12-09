#include "fdf_header.h"

void	print_node_test(t_points *points)
{
	t_points *tempo = points;
	while (tempo)
	{
		printf("%p - %d - %d - %d - %p\n",tempo, tempo->x, tempo->y, tempo->z, tempo->bottom);
		tempo = tempo->next;
	}
	printf("---------------------------------\n");
}

void	print_coords(int ***coords)
{
	int	i;
	int	j;

	i = 0;
	while (coords[i])
	{
		j = 0;
		while(coords[i][j])
		{
			printf("(x : %d, y : %d) - ", coords[i][j][0], coords[i][j][1]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_node(t_points **points)
{
	t_points *tempo;
	int i = 0;

	while (points[i])
	{
		tempo = points[i];
		while (tempo)
		{
			printf("%p -(%d, %d, %d) - %p\n",tempo, tempo->x, tempo->y, tempo->z, tempo->bottom);
			tempo = tempo->next;
		}
		printf("---------------------------------\n");
		i++;
	}
}

// int main()
// {
// 	t_points	*head;
// 	t_points	*head2;
// 	t_points	*head3;
// 	t_points	**arr = ft_calloc(3 + 1, sizeof(t_points *));
	
// 	head = NULL;
// 	add_node(&head, 10, 20, 30);
// 	add_node(&head, 40, 50, 60);
// 	add_node(&head, 70, 80, 90);

// 	head2 = NULL;
// 	add_node(&head2, 100, 200, 300);
// 	add_node(&head2, 400, 500, 600);
// 	add_node(&head2, 700, 800, 900);

// 	head3 = NULL;
// 	add_node(&head3, 100, 200, 300);
// 	add_node(&head3, 400, 500, 600);
// 	add_node(&head3, 700, 800, 900);

// 	arr[0] = head;
// 	arr[1] = head2;
// 	arr[2] = head3;
// 	link_me(arr);
// 	print_node(arr);
// 	// t_points	*tmp;
	
// }