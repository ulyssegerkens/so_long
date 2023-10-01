/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 22:38:04 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/01 22:38:07 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_block	get_next_block(t_data *d, t_direction direction)
{
	t_coord	next;

	next = (t_coord){d->player.x, d->player.y};
	if (direction == UP)
		next.y--;
	else if (direction == DOWN)
		next.y++;
	else if (direction == LEFT)
		next.x--;
	else if (direction == RIGHT)
		next.x++;
	return (d->map->grid[next.y][next.x]);
}

void	move_player_coord(t_data *d, t_direction direction)
{
	if (direction == UP)
		d->player.y--;
	else if (direction == DOWN)
		d->player.y++;
	else if (direction == LEFT)
		d->player.x--;
	else if (direction == RIGHT)
		d->player.x++;
}
