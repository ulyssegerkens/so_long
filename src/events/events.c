/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:18:38 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:20:48 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_data *d)
{
	if (!mlx_loop_hook(d->mlx, hook, d))
		error(d, "mlx_loop_hook failed");
	mlx_close_hook(d->mlx, stop_game, d);
	mlx_key_hook(d->mlx, key_hook, d);
	mlx_loop(d->mlx);
}

void	hook(void *param)
{
	t_data	*d;

	d = param;
	display_next_frame(d);
	if (d->state == END_GAME && !d->frames_queue)
		end_game(d);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*d;

	d = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		stop_game(d);
	if (d->frames_queue)
		return ;
	if (d->state == PLAYING)
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
			move(d, UP);
		else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
			move(d, LEFT);
		else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
			move(d, DOWN);
		else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
			move(d, RIGHT);
	}
}
