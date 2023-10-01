/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:59 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:20:01 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_valid_path(t_data *d, t_map *map)
{
	int		reachable[BLOCK_NUMBER];
	t_coord	pos;

	reachable[COLLECTIBLE] = 0;
	reachable[EXIT] = 0;
	pos = get_position(d->map, PLAYER);
	depth_first_search(map, &pos, init_visited(d, map), reachable);
	if (reachable[COLLECTIBLE] != count_block(map, COLLECTIBLE))
		error(d, "Map should have a valid path to all collectibles");
	if (reachable[EXIT] != 1)
		error(d, "Map should have a valid path to the exit");
}

void	depth_first_search(t_map *map, t_coord *pos, bool **visited,
		int reachable[2])
{
	t_coord	new_pos;
	t_block	current;

	current = map->grid[pos->y][pos->x];
	if (current == EXIT)
		reachable[EXIT] = 1;
	if (visited[pos->y][pos->x] || current == WALL || current == EXIT
		|| current == ENEMY)
		return ;
	visited[pos->y][pos->x] = true;
	if (current == COLLECTIBLE)
		reachable[COLLECTIBLE]++;
	new_pos = (t_coord){pos->x, pos->y - 1};
	depth_first_search(map, &new_pos, visited, reachable);
	new_pos = (t_coord){pos->x, pos->y + 1};
	depth_first_search(map, &new_pos, visited, reachable);
	new_pos = (t_coord){pos->x - 1, pos->y};
	depth_first_search(map, &new_pos, visited, reachable);
	new_pos = (t_coord){pos->x + 1, pos->y};
	depth_first_search(map, &new_pos, visited, reachable);
}

bool	**init_visited(t_data *d, t_map *map)
{
	bool	**visited;
	int		y;

	visited = malloc(sizeof(bool *) * map->height);
	track_allocation(d, visited);
	y = 0;
	while (y < map->height)
	{
		visited[y] = malloc(sizeof(bool) * map->width);
		track_allocation(d, visited[y]);
		ft_memset(visited[y], false, sizeof(bool) * map->width);
		y++;
	}
	return (visited);
}
