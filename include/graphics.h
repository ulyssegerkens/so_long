/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:36:25 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:36:26 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "data.h"

// display_game.c
void	display_game(t_data *d);
void	display_window(t_data *d);
void	display_map(t_data *d);
void	display_status_bar(t_data *d);

//	init_assets.c
void	init_img_set(t_data *d);
void	resize_img_set(t_data *d);
void	init_frame_set(t_data *d);
char	*get_frame_path(t_data *d, t_direction dir, int frame_nb);
void	resize_frames_set(t_data *d);

// animation.c
void	turn_player(t_data *d, t_direction direction);
void	display_next_frame(t_data *d);
void	add_to_frames_queue(t_data *d, int direction, t_coord coord);

// status_bar.c
void	update_move_count(t_data *d);
void	display_count(t_data *d, char *text);

// end_game.c
void	end_game(t_data *d);
void	display_empty(t_data *d);
void	render_centered_image(t_data *d, mlx_image_t *img);
void	open_exit(t_data *d);

// mlx_facades.c
void	render(t_data *d, mlx_image_t *img, t_coord pos);
void	load_img(t_data *d, mlx_image_t **dest_img, char *path);
void	resize_img(t_data *d, mlx_image_t *img, t_size new_size);

// graphics_utils.c
int32_t	px(t_data *d, int32_t x);
t_coord	px_coord(t_data *d, t_coord coord);
void	check_map_size(t_data *d);
void	compute_block_size(t_data *d);

#endif