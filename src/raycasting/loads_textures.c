/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loads_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:46:04 by arbaudou          #+#    #+#             */
/*   Updated: 2025/08/14 23:58:31 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

int load_texture(t_game *game, char *path, t_img *tex)
{
    tex->img = mlx_xpm_file_to_image(game->mlx_ptr, path, &tex->bpp, &tex->line_length);
    if (!tex->img)
        return (-1);
    tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, &tex->endian);
    return (0);
}

int load_all_textures(t_game *game, t_map *map)
{
    if (load_texture(game, map->path_north, &game->tex_north) == -1) return (-1);
    if (load_texture(game, map->path_south, &game->tex_south) == -1) return (-1);
    if (load_texture(game, map->path_east,  &game->tex_east)  == -1) return (-1);
    if (load_texture(game, map->path_west,  &game->tex_west)  == -1) return (-1);
    return (0);
}

