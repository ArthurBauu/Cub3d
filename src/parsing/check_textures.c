/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:52:37 by arbaudou          #+#    #+#             */
/*   Updated: 2025/08/14 23:03:46 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	do_open_texture(const char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	check_textures(t_map *map)
{
	
	trim_newline_end(map->path_north);
	trim_newline_end(map->path_south);
	trim_newline_end(map->path_east);
	trim_newline_end(map->path_west);
	if (!map->path_north || do_open_texture(map->path_north) == -1)
		return (write(2, "Error: North texture missing\n", 29), -1);
	if (!map->path_south || do_open_texture(map->path_south) == -1)
		return (write(2, "Error: South texture missing\n", 29), -1);
	if (!map->path_east || do_open_texture(map->path_east) == -1)
		return (write(2, "Error: East texture missing\n", 28), -1);
	if (!map->path_west || do_open_texture(map->path_west) == -1)
		return (write(2, "Error: West texture missing\n", 28), -1);
	return (0);
}

int	check_colors(t_map *map)
{
	if (map->floor_color < 0 || map->floor_color > 0xFFFFFF)
	{
		write(2, "Error: Invalid floor color\n", 27);
		return (-1);
	}
	if (map->ceiling_color < 0 || map->ceiling_color > 0xFFFFFF)
	{
		write(2, "Error: Invalid ceiling color\n", 29);
		return (-1);
	}
	return (0);
}
int check_valid_chars(t_map *map)
{
    int i, j;

    i = 0;
    while (i < map->map_height)
    {
        j = 0;
        while (j < map->map_width)
        {
            if (map->clean_map[i][j] != '0' && map->clean_map[i][j] != '1' && map->clean_map[i][j] != ' ')
                return (write(2, "Error: Invalid character in map\n", 32), -1);
            j++;
        }
        i++;
    }
    return 0;
}