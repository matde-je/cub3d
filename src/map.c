/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by matilde           #+#    #+#             */
/*   Updated: 2024/02/17 18:46:07 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_name(char *path)
{
	int	i;

	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'c')
		&& (path[i - 2] == 'u' && path[i - 1] == 'b'))
	{
		check_map(path);
		//check_wall();
	}
	else
		error("Invalid map");
}

void	check_map(char *path)
{
	int		i;

	map_global()->fd = open(path, O_RDONLY);
	if (map_global()->fd < 0)
		error("Failed to open file");
	map_global()->gnl = get_next_line(map_global()->fd);
	if (!map_global()->gnl)
		error("Invalid map");
	while (map_global()->gnl)
	{
		i = 0;
		while (map_global()->gnl[i] && map_global()->gnl[i] == ' ')
			i++;
		if (map_global()->gnl[i] != '1')
		{
			free(map_global()->gnl);
			map_global()->gnl = get_next_line(map_global()->fd);
			if (!map_global()->gnl)
				error("Invalid map");
		}
		else
			break ;
	}
	if (map_global()->gnl && map_global()->gnl[i] == '1')
		init_map();
}

void	init_map(void)
{
	t_map	*map1;
	int		max;
	char	*line;
	int		i;

	map1 = map(0);
	max = 0;
	i = 0;
	while (map_global()->gnl != NULL)
	{
		line = rm_space(rm_nl(map_global()->gnl));
		ft_memcpy(map_global()->gnl, line, ft_strlen(line) + 1);
		free(line);
		map1->line = malloc(ft_strlen(map_global()->gnl) + 1);
		if (map1->line == NULL)
			error("Fail to allocate memory");
		ft_memcpy(map1->line, map_global()->gnl, ft_strlen(map_global()->gnl) + 1);
		map1->i = i++;
		max = aux_map(map1, max);
		map1 = map1->next;
	}
	free(map_global()->gnl);
    close(map_global()->fd);
	map_global()->x_max = max;
	map_global()->y_max = i - 1;
}

int	aux_map(t_map *map1, int max)
{
	map1->len = ft_strlen(map1->line);
	if (map1->len > max)
		max = map1->len;
	free(map_global()->gnl);
	map_global()->gnl = get_next_line(map_global()->fd);
	if (map_global()->gnl != NULL)
	{
		map1->next = malloc(sizeof(t_map));
		if (map1->next == NULL)
			error("Fail to allocate memory");
		map1->next->prev = map1;
	}
	else
		map1->next = NULL;
	return (max);
}

// void	check_size(void)
// {
//  if (len < 3 || i < 3)
//  	error("Invalid map");
// }

// void	check_wall(void)
// {
// 	int		count;

// 	count = -1;
// 	while (++count < map(0)->len)
// 	{
// 		if ((map(0)->line[0] != '1' 
// 			|| map(0)->line[map(0)->i -1] != '1'))
// 			error("Invalid walls of map");
// 	}
// 	count = 0;
// 	while (++count < map(0)->i)
// 	{
// 		if ((map(0)->line[count] != '1' 
// 			|| map(0)->line[count] != '1'))
// 			error("Invalid walls of map");
// 	}
// 	check_chars();
// }

// void	check_chars(void)
// {
// 	int	count;
// 	int	pos;
// 	int	count2;

// 	count = 0;
// 	pos = 0;
// 	while (++count < map(0)->i - 1)
// 	{
// 		count2 = 0;
// 		while (++count2 < map(0)->len)
// 		{
// 			if (map(0)->line[count] == 'N')
// 				pos += 1;
// 			else if (map(0)->line[count] != '0' 
// 					&& map(0)->line[count] != '1')
// 				error("Invalid contents in map");
// 		}
// 	}
// 	if (pos != 1)
// 		error("Invalid contents in map");
// }
