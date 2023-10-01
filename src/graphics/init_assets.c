/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:41:12 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/01 22:32:06 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	init_img_set(t_data *d)
{
	ft_bzero(d->img_set, sizeof(d->img_set));
	load_img(d, &d->img_set[EMPTY][0], "assets/blocks/empty.png");
	load_img(d, &d->img_set[WALL][0], "assets/blocks/wall.png");
	load_img(d, &d->img_set[COLLECTIBLE][0], "assets/blocks/collectible.png");
	load_img(d, &d->img_set[ENEMY][0], "assets/blocks/enemy.png");
	load_img(d, &d->img_set[EXIT][CLOSED], "assets/blocks/exit_close.png");
	load_img(d, &d->img_set[EXIT][OPEN], "assets/blocks/exit_open.png");
	load_img(d, &d->img_set[PLAYER][UP], "assets/blocks/player_up.png");
	load_img(d, &d->img_set[PLAYER][DOWN], "assets/blocks/player_down.png");
	load_img(d, &d->img_set[PLAYER][LEFT], "assets/blocks/player_left.png");
	load_img(d, &d->img_set[PLAYER][RIGHT], "assets/blocks/player_right.png");
	resize_img_set(d);
}

void	resize_img_set(t_data *d)
{
	int			row;
	int			col;
	mlx_image_t	*current_img;

	row = 0;
	while (row < BLOCK_NUMBER)
	{
		col = 0;
		while (col < 4)
		{
			current_img = d->img_set[row][col];
			if (current_img)
				resize_img(d, current_img, (t_size){d->block_size, 0});
			col++;
		}
		row++;
	}
}

void	init_frame_set(t_data *d)
{
	int		dir;
	int		frame_nb;
	char	*path;

	ft_bzero(d->frames_set, sizeof(d->frames_set));
	dir = 0;
	while (dir < 4)
	{
		frame_nb = 0;
		while (frame_nb < FRAME_NUMBER)
		{
			path = get_frame_path(d, dir, frame_nb + 1);
			load_img(d, &d->frames_set[dir][frame_nb], path);
			frame_nb++;
		}
		dir++;
	}
	resize_frames_set(d);
}

char	*get_frame_path(t_data *d, t_direction dir, int frame_nb)
{
	int		len;
	char	*path;
	char	*directions;

	(void)d;
	directions = "UDLR";
	len = ft_strlen("assets/frames/D/00.png") + 1;
	path = malloc(len * sizeof(char));
	track_allocation(d, path);
	ft_strlcpy(path, "assets/frames/", len);
	path[14] = directions[dir];
	path[15] = '/';
	path[16] = '0' + frame_nb / 10;
	path[17] = '0' + frame_nb % 10;
	ft_strlcpy(path + 18, ".png", len - 18);
	return (path);
}

void	resize_frames_set(t_data *d)
{
	int	direction;
	int	frame_number;

	direction = 0;
	while (direction < 4)
	{
		frame_number = 0;
		while (frame_number < FRAME_NUMBER)
		{
			if (direction == LEFT || direction == RIGHT)
				resize_img(d, d->frames_set[direction][frame_number],
					(t_size){d->block_size * 2, 0});
			else if (direction == UP || direction == DOWN)
				resize_img(d, d->frames_set[direction][frame_number],
					(t_size){d->block_size, 0});
			frame_number++;
		}
		direction++;
	}
}
