/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:18:58 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:21:08 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	turn_player(t_data *d, t_direction direction)
{
	render(d, d->img_set[PLAYER][direction], px_coord(d, d->player));
}

void	display_next_frame(t_data *d)
{
	t_frame_to_display	*anim;

	if (d->frames_queue == NULL)
		return ;
	if (mlx_get_time() >= d->next_frame_time)
	{
		anim = (t_frame_to_display *)d->frames_queue->content;
		render(d, anim->frame, px_coord(d, anim->place_to_display));
		d->frames_queue = d->frames_queue->next;
		d->next_frame_time = mlx_get_time() + 0.0001f;
	}
}

void	add_to_frames_queue(t_data *d, int direction, t_coord coord)
{
	t_frame_to_display	*frame_to_display;
	t_list				*new_frame;
	int					i;

	i = 0;
	while (i < FRAME_NUMBER)
	{
		frame_to_display = malloc(sizeof(t_frame_to_display));
		track_allocation(d, frame_to_display);
		frame_to_display->frame = d->frames_set[direction][i];
		frame_to_display->place_to_display = coord;
		if (direction == LEFT)
			frame_to_display->place_to_display.x -= 1;
		else if (direction == UP)
			frame_to_display->place_to_display.y -= 1;
		new_frame = ft_lstnew(frame_to_display);
		track_allocation(d, new_frame);
		ft_lstadd_back(&d->frames_queue, new_frame);
		i++;
	}
}
