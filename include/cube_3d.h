#ifndef CUBE_3D_H
# define CUBE_3D_H

#include <stdio.h>
#include <math.h>
#include "parsing.h"
#include "mlx.h"


#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct s_img
{
	void *img;
	char *addr;
	int bpp; // Bits per pixel
	int line_length; // Length of a line in bytes
	int endian; // Endianness of the color format
} t_img;

typedef struct s_player
{
	float x; // Player's X position
	float y; // Player's Y position
	float dir_x; // Direction vector X
	float dir_y; // Direction vector Y
	float plane_x; // Camera plane X
	float plane_y; // Camera plane Y
} t_player;

typedef struct s_game
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
	t_player player;
	t_img tex_north;
	t_img tex_south;
	t_img tex_east;
	t_img tex_west;
}	t_game;

/************** RAYCASTING **************/
int start_engine(t_map *map);
void	init_player(t_player *player, t_map *map);
void	draw_background(t_img *img, int floor_color, int ceiling_color);
void	draw_pixel(t_img *img, int x, int y, int color);
int	get_color_from_texture(t_map *map, int texture_index, float u, float v);


t_img *get_texture(t_game *game, int side, float ray_dir_x, float ray_dir_y);
void render_frame(t_game *game, t_map *map);
int load_all_textures(t_game *game, t_map *map);
void draw_wall_slice(t_img *img, t_img *tex, int x, int draw_start, int draw_end, float wall_x);

void print_struct(t_map *map);


/************** INIT **************/

void	init_player(t_player *player, t_map *map);


/************** UTILS **************/
void	free_struct(t_map *map);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);


#endif
