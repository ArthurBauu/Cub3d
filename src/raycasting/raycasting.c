/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 21:10:01 by arbaudou          #+#    #+#             */
/*   Updated: 2025/08/14 23:58:44 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"


void put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;

    dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
    *(unsigned int*)dst = color;
}

void draw_background(t_img *img, int floor_color, int ceiling_color)
{
	int x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, ceiling_color);
			x++;
		}
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(img, x, y, floor_color);
			x++;
		}
		y++;
	}
}


int start_engine(t_map *map)
{
	t_game game;

	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		return (write(2, "Error: Failed to initialize MLX\n", 33), -1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cube_3D");
	if (!game.win_ptr)
		return (write(2, "Error: Failed to create window\n", 32), -1);
	game.img.img = mlx_new_image(game.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!game.img.img)
		return (write(2, "Error: Failed to create image\n", 31), -1);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bpp,
			&game.img.line_length, &game.img.endian);
	init_player(&game.player, map);
	draw_background(&game.img, map->floor_color, map->ceiling_color);
	render_frame(&game, map);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img.img, 0, 0);
	mlx_loop(game.mlx_ptr);
	return (0);
}
