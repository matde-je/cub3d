/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-je <matde-je@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:13:53 by matde-je          #+#    #+#             */
/*   Updated: 2024/05/16 19:37:36 by matde-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	xpm_to_pixel(char *xpm, int i)
{
	void	*ptr;
	int		*addr;
	int		x;
	int		y;

	ptr = mlx_xpm_file_to_image(c3d()->mlx, xpm, &c3d()->tex2[i].width, \
			&c3d()->tex2[i].height);
	c3d()->tex2[i].ptr = ptr;
	addr = (int *)mlx_get_data_addr(c3d()->tex2[i].ptr, &c3d()->tex2[i].bpp, \
			&c3d()->tex2[i].size, &c3d()->tex2[i].endian);
	c3d()->tex2[i].addr = addr;
	y = -1;
	if (!c3d()->tex2[i].addr)
		error("Error on img addr");
	while (++y < c3d()->tex2[i].height)
	{
		x = -1;
		while (++x < c3d()->tex2[i].width)
		{
			c3d()->tex[i][c3d()->tex2[i].height * y \
				+ x] = (c3d()->tex2[i].addr[c3d()->tex2[i].height * y + x]);
		}
	}
	mlx_destroy_image(c3d()->mlx, c3d()->tex2[i].ptr);
}

int	init_tex(void)
{
	xpm_to_pixel(c3d()->t.ea, EAST);
	xpm_to_pixel(c3d()->t.no, NORTH);
	xpm_to_pixel(c3d()->t.so, SOUTH);
	xpm_to_pixel(c3d()->t.we, WEST);
	return (0);
}
