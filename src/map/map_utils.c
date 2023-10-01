/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:55 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:19:57 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	count_block(t_map *map, t_block block_type)
{
	int		count;
	t_coord	coord;

	count = 0;
	coord.y = -1;
	while (++coord.y < map->height)
	{
		coord.x = -1;
		while (++coord.x < map->width)
			if (map->grid[coord.y][coord.x] == block_type)
				count++;
	}
	return (count);
}

t_coord	get_position(t_map *map, t_block block_type)
{
	t_coord	coord;

	coord.y = 0;
	while (coord.y < map->height)
	{
		coord.x = 0;
		while (coord.x < map->width)
		{
			if (map->grid[coord.y][coord.x] == block_type)
				return (coord);
			coord.x++;
		}
		coord.y++;
	}
	return (coord);
}
