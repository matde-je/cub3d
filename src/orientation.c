/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:07:05 by matilde           #+#    #+#             */
/*   Updated: 2024/03/18 18:04:31 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	player_angle(void)
{
	t_map	*map1;
	int		player_angle;

	map1 = map();
	while (map1 && map1->i != map_global()->pos_y)
		map1 = map1->next;
	if (map1->line[map_global()->pos_x] == 'N')
		player_angle = 0;
	else if (map1->line[map_global()->pos_x] == 'S')
		player_angle = 180;
	else if (map1->line[map_global()->pos_x] == 'E')
		player_angle = 90;
	else if (map1->line[map_global()->pos_x] == 'W')
		player_angle = 270;
	return (player_angle);
}

int	calculate_texture_index(void)
{
	int	pos;
	int	player;

	pos = -1;
	player = player_angle();
	if (player == 0)
	{
		pos = 'N';
		if (ray()->intersect_x < map_global()->pos_x)
			pos = 'E';
		else if (ray()->intersect_x > map_global()->pos_x)
			pos = 'W';
	}
	else if (player == 180)
	{
		pos = 'S';
		if (ray()->intersect_x < map_global()->pos_x)
			pos = 'E';
		else if (ray()->intersect_x > map_global()->pos_x)
			pos = 'W';
	}
	else
		texture_index(player, &pos);
	return (pos);
}

void	texture_index(int player, int *pos)
{
	if (player == 90)
	{
		*pos = 'O';
		if (ray()->intersect_y > map_global()->pos_y)
			*pos = 'N';
		else if (ray()->intersect_y < map_global()->pos_y)
			*pos = 'S';
	}
	else if (player == 270)
	{
		*pos = 'E';
		if (ray()->intersect_y > map_global()->pos_y)
			*pos = 'N';
		else if (ray()->intersect_y < map_global()->pos_y)
			*pos = 'S';
	}
}

void	render_cube(float distance)
{
	int	cube_size;
	int	pos;
	int	player;

	cube_size = (map_global()->x_max * 32) / distance;
	player = player_angle();
	pos = calculate_texture_index();
	if (pos == -1)
		return ;
	if (player == 0)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img['N'], \
		ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2);
	else if (player == 180)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img['S'], ray()->intersect_x - cube_size / 2, \
		((ray()->intersect_y - cube_size) / 2) + cube_size);
	else if (player == 270)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img['E'], ray()->intersect_x - cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	else if (player == 90)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img['W'], ray()->intersect_x + cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	if (pos == 'W' && player != 90)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], ray()->intersect_x - cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	else if (pos == 'E' && player != 270)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], ray()->intersect_x + cube_size / 2, \
		ray()->intersect_y - cube_size / 2);
	else if (pos == 'N' && player != 0)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], \
		ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2);
	else if (pos == 'S' && player != 180)
		mlx_put_image_to_window(window()->mlx, window()->window_ptr, \
		window()->img[pos], ray()->intersect_x - cube_size / 2, \
		((ray()->intersect_y - cube_size) / 2) + cube_size);
}

// int front_vertices[4][2] = {
//{ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2},
//Front bottom left
// int left_vertices[4][2] = {
//{ray()->intersect_x - cube_size / 2, ray()->intersect_y - cube_size / 2},
//Left bottom front
// int right_vertices[4][2] = {
//{ray()->intersect_x + cube_size / 2, ray()->intersect_y - cube_size / 2},
//Right bottom front