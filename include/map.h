/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:36:38 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 18:30:06 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "data.h"

// init_map.c
void	init_map(t_data *d, char *map_path);

// import_map.c
void	import_map(t_data *d, char *map_path);
void	set_width_height(t_data *d, t_map *map, char *map_path);
void	update_width_height(t_map *map, char *buffer, ssize_t bytes_read);
void	init_map_grid(t_data *d, t_map *map, int width, int height);
void	map_file_to_map_grid(t_data *d, t_map *map, char *map_path);

// import_map_utils.c
void	cut_nl(char *line);
void	line_to_grid(t_block **grid, char *line, int row);
t_block	char_to_block(char c);
void	reading_error(t_data *d, char *description, int fd);

// map_utils.c
int		count_block(t_map *map, t_block block_type);
t_coord	get_position(t_map *map, t_block block_type);

// map_validity.c
void	check_map_validity(t_data *d, t_map *map);
bool	is_surrounded_by_wall(t_map *map);

// map_validity_path.c
void	check_valid_path(t_data *d, t_map *map);
void	depth_first_search(t_map *map, t_coord *pos, bool **visited,
			int reachable[2]);
bool	**init_visited(t_data *d, t_map *map);

#endif
