# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acuva-nu <acuva-nu@student.42lisboa.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by                   #+#    #+#              #
#    Updated: 2024/04/29 22:13:17 by acuva-nu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    = main.c keys.c parse_map.c utils.c check_walls.c get_next_line.c    \
		  parse_textures.c textures.c parse_rgb.c utils2.c utils.c raycast.c \
		  cameras.c render.c 
			
#Add any missing folder containing a .c to the vpath
vpath %.c gnl/ src/parse  src/ 

OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
INCS 	   = ../cub3d.h
NAME       = cub3D
CC         = cc
CFLAGS     = -g -Wall -Wextra -Werror #-fsanitize=address
LDFLAGS	   = -L./libft -lft   -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz 
RM         = rm -rf

all: ${NAME}

$(OBJ_DIR)/%.o: %.c 
	@mkdir -p ${OBJ_DIR}
	$(CC) $(CFLAGS) -c $< -o $@
	
${NAME}: ${OBJS} 
	make -s -C libft
	${CC} ${CFLAGS}  $^ -o $@  -I ${INCS} ${LDFLAGS}

clean:
	${RM} ${OBJ_DIR} 
	make clean -s -C libft

fclean: clean
	${RM} ${NAME} 
	make fclean -s -C libft

re: fclean all

# norm:
# 	norminette -R CheckForbiddenSourceHeader ${SRCS}
# 	norminette -R CheckDefine ${INCS}

.PHONY: all re clean fclean 
