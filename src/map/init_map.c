/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:49 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:19:51 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	init_map(t_data *d, char *map_path)
{
	d->map = malloc(sizeof(t_map));
	track_allocation(d, d->map);
	d->map->grid = NULL;
	d->map->width = 0;
	d->map->height = 0;
	import_map(d, map_path);
	check_map_validity(d, d->map);
}
