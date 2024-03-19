/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:52:48 by matilde           #+#    #+#             */
/*   Updated: 2024/03/19 16:18:07 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error("Number of arguments");
	parsing(argv[1]);
	new_window();
	mlx_key_hook(window()->win, key_handler, NULL);
	mlx_hook(window()->win, 17, 131072, &free_all, NULL);
	if (window()->win)
		mlx_loop(window()->mlx);
	free_all(0);
	return (0);
}

void	error(char	*str)
{
	int	i;

	i = -1;
	write(1, "Error\n", 6);
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 1);
	free_all(1);
	exit(1);
}
