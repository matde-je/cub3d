/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matilde <matilde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:47:16 by matilde           #+#    #+#             */
/*   Updated: 2024/02/15 17:00:29 by matilde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 0xff1b
# define A 0x61
# define W 0x77
# define D 0x64
# define S 0x73

# include "libft/inc/libft.h"
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_map
{
	int		size_x;
	int		size_y;
	char	**matrix;
}				t_map;

typedef struct s_window
{
	char	*window_ptr;
	char	*mlx_ptr;
	void	*img[200];
}				t_window;

t_map		*map(void);
t_window	*window(void);
void		check_name(char *path);
void		check_wall(void);
int			key_handler(int key);
int			free_all(int i);
void		error(char	*str);
char		*get_next_line(int fd);
char		*ft_strjoin1(char *linha, char *buffer);
void		check_map(char *path);
void		init_matrix(char *path, int len, int size_y);
void		check_size(char *gnl, int fd, char *path);
void		check_map(char *path);
char		*rm_nl(char	*str);
char		*ft_strcpy(char *dest, char *src);
void		check_chars(void);
void		new_window(void);
void		window_img(void);

#endif