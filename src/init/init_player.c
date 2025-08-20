/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:26:35 by arbaudou          #+#    #+#             */
/*   Updated: 2025/08/14 21:27:22 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

void	init_player(t_player *player, t_map *map)
{
	player->x = map->start_x + 0.5;
	player->y = map->start_y + 0.5;

	if (map->start_orientation == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (map->start_orientation == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (map->start_orientation == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (map->start_orientation == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}
