/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+		+#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/03/20 11:09:27 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


t_c3d *cub3(void)
{
    static t_c3d var;

    var.height = WIN_HEIGHT;
    var.width = WIN_WIDTH;
    var.mlx = mlx_init();
    var.win = mlx_new_window(var.mlx, var.width, var.height, "cub3D");
    return (&var);
}

int start_all(void)
{
    render_floor();
    render_ceiling();
    raycasting();
    cub3()->framerate = 16 /1000.0;
    cub3()->move_speed = cub3()->framerate * 5.0;
    cub3()->rota_speed = cub3()->framerate * 3.0;
    mlx_destroy_image(cub3()->mlx, cub3()->image.img_ptr);
    return (0);
}

int	main(int argc, char **argv)
{

	if (argc != 2)
		error("Number of arguments");
	parsing(argv[1]);
    mlx_loop_hook(cub3()->mlx, start_all, NULL);
	mlx_key_hook(window()->win, key_handler, NULL);
	mlx_hook(window()->win, 17, 131072, &free_all, NULL);
	if (window()->win)
		mlx_loop(window()->mlx);
	free_all(0);
	return (0);
}

void	error(char *str)
{
	int	i;

	i = -1;
	write(2, "Error\n", 6);
	while (str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 1);
	free_all(1);
	exit(1);
}

