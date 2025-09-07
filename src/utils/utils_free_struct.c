/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:44:54 by arbaudou          #+#    #+#             */
/*   Updated: 2025/09/04 10:45:41 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"
#include "parsing.h"

void	cleanup_engine(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx_ptr, game->img.img);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_struct(t_map *map)
{
	if (!map)
		return ;
	if (map->path_north)
		free(map->path_north), map->path_north = NULL;
	if (map->path_south)
		free(map->path_south), map->path_south = NULL;
	if (map->path_east)
		free(map->path_east), map->path_east = NULL;
	if (map->path_west)
		free(map->path_west), map->path_west = NULL;
	if (map->map_data)
	{
		ft_free_tab(map->map_data);
		map->map_data = NULL;
	}
	if (map->clean_map)
	{
		ft_free_tab(map->clean_map);
		map->clean_map = NULL;
	}
}
