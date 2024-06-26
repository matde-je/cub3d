/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:11:59 by matilde           #+#    #+#             */
/*   Updated: 2024/04/15 14:08:39 by acuva-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parsing(char *path)
{
	int		i;
	t_map	*mp;

	mp = map();
	i = ft_strlen(path);
	if ((path[i - 4] == '.' && path[i - 3] == 'c') && (path[i - 2] == 'u'
			&& path[i - 1] == 'b'))
	{
		c3d()->mg.path = malloc(ft_strlen(path) + 1);
		if (c3d()->mg.path == NULL)
			error("Fail to allocate memory");
		ft_strlcpy(c3d()->mg.path, path, ft_strlen(path) + 1);
		check_map(path, 0);
		check_chars(-1, 0, mp);
		check_wall(0);
		check_walls();
		c3d()->mg.gnl = NULL;
		open_textures(path);
		prep_texture(0, 0, NULL, NULL);
	}
	else
		error("Invalid map path");
}

void	check_map(char *path, int i)
{
	(c3d()->mg.fd) = open(path, O_RDONLY);
	if (c3d()->mg.fd < 0)
		error("Failed to open file");
	(c3d()->mg.gnl) = (get_next_line(c3d()->mg.fd, 0, 0, NULL));
	if (!c3d()->mg.gnl)
		error("Invalid map1");
	while (c3d()->mg.gnl)
	{
		i = 0;
		while (c3d()->mg.gnl[i] && c3d()->mg.gnl[i] == ' ')
			i++;
		if (c3d()->mg.gnl[i] != '1')
		{
			free(c3d()->mg.gnl);
			(c3d()->mg.gnl) = (get_next_line(c3d()->mg.fd, 0, 0, NULL));
			if (!c3d()->mg.gnl)
				error("Invalid map2");
		}
		else
			break ;
	}
	if (c3d()->mg.gnl && c3d()->mg.gnl[i] == '1')
		init_map(0, 0, NULL, map());
}

void	init_map(int i, int max, char *line, t_map *map1)
{
	while (c3d()->mg.gnl != NULL)
	{
		line = rm_space(rm_nl(c3d()->mg.gnl));
		if (!line)
		{
			map1->prev->next = NULL;
			free(map1);
			break ;
		}
		ft_memcpy(c3d()->mg.gnl, line, ft_strlen(line) + 1);
		map1->line = malloc(ft_strlen(c3d()->mg.gnl) + 1);
		if (map1->line == NULL)
			error("Fail to allocate memory");
		ft_memcpy(map1->line, c3d()->mg.gnl, ft_strlen(c3d()->mg.gnl) + 1);
		map1->i = i++;
		max = aux_map(map1, max);
		map1 = map1->next;
	}
	free(c3d()->mg.gnl);
	c3d()->mg.gnl = NULL;
	close(c3d()->mg.fd);
	c3d()->mg.x_max = max;
	c3d()->mg.y_max = i;
}

int	aux_map(t_map *map1, int max)
{
	map1->len = ft_strlen(map1->line);
	if (map1->len > max)
		max = map1->len;
	free(c3d()->mg.gnl);
	(c3d()->mg.gnl) = (get_next_line(c3d()->mg.fd, 0, 0, NULL));
	if (c3d()->mg.gnl != NULL)
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
