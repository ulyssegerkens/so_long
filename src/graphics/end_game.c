/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:12 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:19:14 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	end_game(t_data *d)
{
	mlx_image_t	*end_img;

	display_empty(d);
	if (d->map->grid[d->player.y][d->player.x] == EXIT)
		load_img(d, &end_img, "assets/end_game/you_win.png");
	else
		load_img(d, &end_img, "assets/end_game/game_over.png");
	resize_img(d, end_img, (t_size){d->window.width * 0.6, 0});
	render_centered_image(d, end_img);
	d->state = END_SCREEN;
}

void	display_empty(t_data *d)
{
	t_coord		coord;
	mlx_image_t	*current_img;

	coord.y = 0;
	while (coord.y < d->map->height)
	{
		coord.x = 0;
		while (coord.x < d->map->width)
		{
			current_img = d->img_set[EMPTY][0];
			render(d, current_img, px_coord(d, coord));
			coord.x++;
		}
		coord.y++;
	}
}

void	render_centered_image(t_data *d, mlx_image_t *img)
{
	t_coord	pos;

	pos.x = (d->window.width - img->width) / 2;
	pos.y = (d->window.height - img->height) / 2;
	render(d, img, pos);
}

void	open_exit(t_data *d)
{
	render(d, d->img_set[EXIT][d->exit_status], px_coord(d, d->exit));
}
