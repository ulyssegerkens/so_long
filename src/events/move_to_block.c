/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_block.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:18:47 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:20:58 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	to_any(t_data *d, t_direction direction)
{
	add_to_frames_queue(d, direction, d->player);
	d->map->grid[d->player.y][d->player.x] = EMPTY;
	move_player_coord(d, direction);
	update_move_count(d);
}

void	to_collectible(t_data *d, t_direction direction)
{
	to_any(d, direction);
	d->collectible_count--;
	if (d->collectible_count == 0)
	{
		d->exit_status = OPEN;
		open_exit(d);
	}
}

void	to_exit(t_data *d, t_direction direction)
{
	if (d->exit_status == CLOSED)
		return ;
	to_any(d, direction);
	d->state = END_GAME;
}

void	to_enemy(t_data *d, t_direction direction)
{
	to_any(d, direction);
	d->state = END_GAME;
}
