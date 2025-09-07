/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:26:35 by arbaudou          #+#    #+#             */
/*   Updated: 2025/09/04 10:49:47 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

void	init_player2(t_player *player, t_map *map)
{
	if (map->start_orientation == 2) // East
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (map->start_orientation == 3) // West
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

void	init_player(t_player *player, t_map *map)
{
	player->x = map->start_x + 0.5;
	player->y = map->start_y + 0.5;
	if (map->start_orientation == 0) // North
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (map->start_orientation == 1) // South
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (map->start_orientation == 2 || map->start_orientation == 3)
		init_player2(player, map);
}

void	init_keys(t_keys *keys)
{
	keys->w = 0;
	keys->s = 0;
	keys->a = 0;
	keys->d = 0;
	keys->left = 0;
	keys->right = 0;
}
