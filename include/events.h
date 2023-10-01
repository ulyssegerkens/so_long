/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:36:29 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:36:30 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "data.h"

// event.c
void	start_game(t_data *d);
void	hook(void *param);
void	key_hook(mlx_key_data_t keydata, void *param);

// move.c
void	move(t_data *d, t_direction direction);
void	turn(t_data *d, t_direction direction);

// move_to_block.c
void	to_any(t_data *d, t_direction direction);
void	to_collectible(t_data *d, t_direction direction);
void	to_exit(t_data *d, t_direction direction);
void	to_enemy(t_data *d, t_direction direction);

// move_utils.c
t_block	get_next_block(t_data *d, t_direction direction);
void	move_player_coord(t_data *d, t_direction direction);

#endif