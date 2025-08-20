/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arbaudou <arbaudou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:45:20 by arbaudou          #+#    #+#             */
/*   Updated: 2025/08/14 21:09:46 by arbaudou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

int	main(int argc, char **argv)
{
	t_map *map;
	int error_code;
	
	if (argc != 2)
	{
		write(2, "Usage: ./cube_3d <input_file>\n", 30);
		return (1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
	{
		write(2, "Error: Memory allocation failed for map\n", 40);
		return (1);
	}
	init_map(map);
	if (parse(argv[1], map) == -1)
		error_code = 1;
	else
		start_engine(map);
	print_struct(map);
	free_struct(map);
	free(map);
	return (error_code);
}
