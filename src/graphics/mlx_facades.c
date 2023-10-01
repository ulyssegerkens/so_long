/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_facades.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:26 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 00:19:29 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

void	render(t_data *d, mlx_image_t *img, t_coord pos)
{
	if (mlx_image_to_window(d->mlx, img, pos.x, pos.y) < 0)
		error(d, "mlx_image_to_window failed");
}

void	load_img(t_data *d, mlx_image_t **dest_img, char *path)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
		error(d, "mlx_load_png failed");
	*dest_img = mlx_texture_to_image(d->mlx, texture);
	if (!*dest_img)
		error(d, "mlx_texture_to_image failed");
	mlx_delete_texture(texture);
}

void	resize_img(t_data *d, mlx_image_t *img, t_size new_size)
{
	if (new_size.height == 0)
		new_size.height = (img->height * new_size.width) / img->width;
	if (!mlx_resize_image(img, new_size.width, new_size.height))
		error(d, "mlx_resize_image failed");
}
