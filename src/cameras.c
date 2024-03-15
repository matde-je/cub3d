/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cameras.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:39:08 by matilde           #+#    #+#             */
/*   Updated: 2024/03/05 17:39:16 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//camera looks left
void	look_left(void)
{
	t_map	*map1;
	int		i;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N' || map1->line[i] == 'S' \
				|| map1->line[i] == 'E' || map1->line[i] == 'W')
			{
				map1->line[i] -= 32;
				return ;
			}
		}
		map1 = map1->next;
	}
}

//camera look right
void	look_right(void)
{
	t_map	*map1;
	int		i;

	map1 = map();
	while (map1)
	{
		i = -1;
		while (++i < map1->len)
		{
			if (map1->line[i] == 'N' || map1->line[i] == 'S' \
				|| map1->line[i] == 'E' || map1->line[i] == 'W')
			{
				map1->line[i] += 32;
				return ;
			}
		}
		map1 = map1->next;
	}
}