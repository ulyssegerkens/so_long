/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugerkens <ugerkens@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 00:19:37 by ugerkens          #+#    #+#             */
/*   Updated: 2025/01/22 18:30:01 by ugerkens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	cut_nl(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
}

void	line_to_grid(t_block **grid, char *line, int row)
{
	int	i;

	i = 0;
	while (line[i])
	{
		grid[row][i] = char_to_block(line[i]);
		i++;
	}
}

t_block	char_to_block(char c)
{
	if (c == '0')
		return (EMPTY);
	else if (c == '1')
		return (WALL);
	else if (c == 'C')
		return (COLLECTIBLE);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'P')
		return (PLAYER);
	else
		return (NULL_BLOCK);
}

void	reading_error(t_data *d, char *description, int fd)
{
	close(fd);
	error(d, description);
}
