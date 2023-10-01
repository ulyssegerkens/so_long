/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:04:27 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/01 21:09:01 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

// Standard libraries
# include <errno.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// 42 libraries
# include "MLX42.h"
// Personal libraries
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_coord
{
	int32_t			x;
	int32_t			y;
}					t_coord;

typedef struct s_size
{
	int32_t			width;
	int32_t			height;
}					t_size;

typedef enum t_exit_status
{
	CLOSED,
	OPEN
}					t_exit_status;

typedef enum t_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}					t_direction;

# define BLOCK_NUMBER 7

typedef enum t_block
{
	NULL_BLOCK,
	EMPTY,
	WALL,
	COLLECTIBLE,
	ENEMY,
	EXIT,
	PLAYER
}					t_block;

typedef enum states
{
	PLAYING,
	END_GAME,
	END_SCREEN
}					t_states;

typedef struct s_map
{
	t_block			**grid;
	int32_t			width;
	int32_t			height;
}					t_map;

# define FRAME_NUMBER 12

typedef struct s_frame_to_display
{
	mlx_image_t		*frame;
	t_coord			place_to_display;
}					t_frame_to_display;

typedef struct s_data
{
	t_list			*allocated_pointers;
	t_states		state;
	mlx_t			*mlx;
	t_size			window;
	int32_t			block_size;
	mlx_image_t		*img_set[BLOCK_NUMBER][4];
	mlx_image_t		*frames_set[4][FRAME_NUMBER];
	t_list			*frames_queue;
	float			next_frame_time;
	mlx_image_t		*move_count_img;
	int				move_count;
	t_map			*map;
	t_coord			player;
	t_direction		player_orientation;
	t_coord			exit;
	t_exit_status	exit_status;
	int				collectible_count;
}					t_data;

// Forward Declarations
void				error(t_data *d, char *description);
void				track_allocation(t_data *d, void *pointer);

#endif
