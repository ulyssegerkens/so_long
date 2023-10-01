/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:18:53 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:18:56 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *d, t_direction direction)
{
	t_block	next_block;

	if (d->player_orientation != direction)
		turn(d, direction);
	else
	{
		next_block = get_next_block(d, direction);
		if (next_block == EMPTY)
			to_any(d, direction);
		else if (next_block == COLLECTIBLE)
			to_collectible(d, direction);
		else if (next_block == ENEMY)
			to_enemy(d, direction);
		else if (next_block == EXIT)
			to_exit(d, direction);
	}
}

void	turn(t_data *d, t_direction direction)
{
	turn_player(d, direction);
	d->player_orientation = direction;
	update_move_count(d);
}
