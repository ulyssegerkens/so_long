/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:06 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:19:08 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	display_game(t_data *d)
{
	check_map_size(d);
	compute_block_size(d);
	display_window(d);
	init_img_set(d);
	d->frames_queue = NULL;
	d->next_frame_time = 0;
	init_frame_set(d);
	display_map(d);
	display_status_bar(d);
}

void	display_window(t_data *d)
{
	d->window.width = px(d, d->map->width);
	d->window.height = px(d, d->map->height);
	d->window.height += 60;
	d->mlx = mlx_init(d->window.width, d->window.height, "So Long", true);
	if (!d->mlx)
		error(d, "mlx_init failed");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
}

void	display_map(t_data *d)
{
	t_coord		coord;
	t_block		current_block;
	mlx_image_t	*current_img;

	coord.y = 0;
	while (coord.y < d->map->height)
	{
		coord.x = 0;
		while (coord.x < d->map->width)
		{
			current_block = d->map->grid[coord.y][coord.x];
			current_img = d->img_set[current_block][0];
			render(d, current_img, px_coord(d, coord));
			coord.x++;
		}
		coord.y++;
	}
}

void	display_status_bar(t_data *d)
{
	mlx_image_t	*black_rect;

	d->move_count = 0;
	load_img(d, &black_rect, "assets/blocks/empty.png");
	resize_img(d, black_rect, (t_size){d->window.width, 0});
	render(d, black_rect, (t_coord){0, d->window.height - 60});
	display_count(d, "0");
}
