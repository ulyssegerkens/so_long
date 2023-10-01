/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valididy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:20:04 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:25:15 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	check_map_validity(t_data *d, t_map *map)
{
	if (count_block(map, NULL_BLOCK) > 0)
		error(d, "Invalid character in map");
	if (count_block(map, PLAYER) != 1)
		error(d, "Map should have exactly one starting point");
	if (count_block(map, EXIT) != 1)
		error(d, "Map should have exactly one exit");
	if (count_block(map, COLLECTIBLE) < 1)
		error(d, "Map should have at least one collectible");
	if (!is_surrounded_by_wall(map))
		error(d, "Map should be surrounded by walls");
	check_valid_path(d, map);
}

bool	is_surrounded_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != WALL || map->grid[map->height - 1][i] != WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != WALL || map->grid[i][map->width - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}
