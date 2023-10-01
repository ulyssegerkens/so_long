/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:16 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:21:16 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int32_t	px(t_data *d, int32_t xy)
{
	return (xy * d->block_size);
}

t_coord	px_coord(t_data *d, t_coord coord)
{
	coord.x = px(d, coord.x);
	coord.y = px(d, coord.y);
	return (coord);
}

void	check_map_size(t_data *d)
{
	if (d->map->width > 140 || d->map->height > 70)
		error(d, "Map is too big to be displayed on screen");
}

void	compute_block_size(t_data *d)
{
	t_size	potential;

	potential.width = (5120 / 3) / d->map->width;
	potential.height = (2880 / 3) / d->map->height;
	if (potential.width < potential.height)
		d->block_size = potential.width;
	else
		d->block_size = potential.height;
}
