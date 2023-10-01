/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_bar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:32 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:19:34 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	update_move_count(t_data *d)
{
	char	*count_txt;

	if (ft_printf("Moves: %d\n", ++d->move_count) < 0)
		error(d, "ft_printf failed");
	mlx_delete_image(d->mlx, d->move_count_img);
	count_txt = ft_itoa(d->move_count);
	track_allocation(d, count_txt);
	display_count(d, count_txt);
}

void	display_count(t_data *d, char *count_txt)
{
	mlx_image_t	*count_img;
	t_size		size;
	t_coord		coord;

	coord = (t_coord){0, -100};
	count_img = mlx_put_string(d->mlx, count_txt, coord.x, coord.y);
	if (!count_img)
		error(d, "mlx_put_string failed");
	size.height = 55;
	size.width = (count_img->width * size.height) / count_img->height;
	resize_img(d, count_img, size);
	coord.x = (d->window.width / 2) - (count_img->width / 2);
	coord.y = d->window.height - 60;
	render(d, count_img, coord);
	d->move_count_img = count_img;
}
