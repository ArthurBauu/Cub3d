/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:16:33 by arbaudou          #+#    #+#             */
/*   Updated: 2025/08/12 20:19:48 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void init_map(t_map *map)
{
	map->path_north = NULL;
	map->path_south = NULL;
	map->path_east = NULL;
	map->path_west = NULL;
	map->map_data = NULL;
	map->start_orientation = 0;
	map->floor_color = 0;
	map->ceiling_color = 0;
	map->map_width = 0;
	map->map_height = 0;
}