/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:45 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:47:23 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	import_map(t_data *d, char *map_path)
{
	set_width_height(d, d->map, map_path);
	init_map_grid(d, d->map, d->map->width, d->map->height);
	map_file_to_map_grid(d, d->map, map_path);
}

void	set_width_height(t_data *d, t_map *map, char *map_path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error(d, strerror(errno));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			reading_error(d, "read function failed", fd);
		update_width_height(map, buffer, bytes_read);
	}
	if (map->width > 0)
		map->height++;
	close(fd);
}

void	update_width_height(t_map *map, char *buffer, ssize_t bytes_read)
{
	int	i;

	i = 0;
	while (map->height == 0 && buffer[i] != '\n' && i < bytes_read)
	{
		map->width++;
		i++;
	}
	while (i < bytes_read)
		if (buffer[i++] == '\n')
			map->height++;
}

void	init_map_grid(t_data *d, t_map *map, int width, int height)
{
	int	y;

	map->grid = malloc(height * sizeof(t_block *));
	track_allocation(d, map->grid);
	y = 0;
	while (y < height)
	{
		map->grid[y] = malloc(width * sizeof(t_block));
		track_allocation(d, map->grid[y]);
		y++;
	}
}

void	map_file_to_map_grid(t_data *d, t_map *map, char *map_path)
{
	int		fd;
	int		y;
	int		width;
	char	*line;

	width = map->width;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		error(d, strerror(errno));
	y = 0;
	while (y < map->height)
	{
		if (get_next_line(fd, &line) == EXIT_FAILURE)
			reading_error(d, "get_next_line failed", fd);
		cut_nl(line);
		if ((int)ft_strlen(line) != width)
			reading_error(d, "Inconsistent line length in map file", fd);
		line_to_grid(map->grid, line, y);
		free(line);
		y++;
	}
	close(fd);
}
