/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:36:33 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:36:34 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "data.h"
# include "events.h"
# include "graphics.h"
# include "map.h"

// main.c
int		main(int argc, char **argv);
void	stop_game(void *param);
void	error(t_data *d, char *description);

// data.c
void	init_data(t_data *d, char *map_path);
void	free_data(t_data *d);
void	track_allocation(t_data *d, void *pointer);

#endif
