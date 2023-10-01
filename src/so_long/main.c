/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:20:18 by ugerkens          #+#    #+#             */
/*   Updated: 2023/09/02 17:26:04 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	d;

	if (argc != 2)
		error(NULL, "Wrong number of arguments");
	init_data(&d, argv[1]);
	display_game(&d);
	start_game(&d);
	return (EXIT_SUCCESS);
}

void	stop_game(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	mlx_close_window(d->mlx);
	free_data(d);
	exit(EXIT_SUCCESS);
}

void	error(t_data *d, char *description)
{
	free_data(d);
	ft_printf("Error\n%s\n", description);
	exit(EXIT_FAILURE);
}
