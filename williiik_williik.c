t_points	**get_coords(char **lines, int w, int h)
{
	int			lines_counts;
	t_points	**points;
	int			i;
	int			j;
	char		**line;
	int			x_y_counts[2];

	x_y_counts[0] = get_lines_counts(ft_split(lines[0], ' '));
	x_y_counts[1] = get_lines_counts(lines);
	lines_counts = get_lines_counts(lines);
	points = ft_calloc(lines_counts + 1, sizeof(t_points *));
	i = -1;
	while (++i < lines_counts)
	{
		j = -1;
		line = ft_split(lines[i], ' ');
		points[i] = NULL;
		while (line[++j])
			add_node(&points[i], ((w - 300) / x_y_counts[0]) * j,
				((h) / x_y_counts[1]) * i, ft_atoi(line[j]) * 3);
		free (line);
	}
	return (points);
}
