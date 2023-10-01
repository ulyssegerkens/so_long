/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:20:14 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 17:24:22 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_data *d, char *map_path)
{
	d->allocated_pointers = NULL;
	d->state = PLAYING;
	d->mlx = NULL;
	init_map(d, map_path);
	d->player = get_position(d->map, PLAYER);
	d->player_orientation = UP;
	d->exit = get_position(d->map, EXIT);
	d->exit_status = CLOSED;
	d->collectible_count = count_block(d->map, COLLECTIBLE);
}

void	free_data(t_data *d)
{
	if (!d)
		return ;
	ft_lstclear(&d->allocated_pointers, &free);
	if (d->mlx)
		mlx_terminate(d->mlx);
}

void	track_allocation(t_data *d, void *pointer)
{
	t_list	*new_node;

	(void)d;
	if (!pointer)
		error(d, "A memory allocation failed");
	new_node = ft_lstnew(pointer);
	if (!new_node)
		error(d, "A memory allocation failed");
	ft_lstadd_front(&d->allocated_pointers, new_node);
}
