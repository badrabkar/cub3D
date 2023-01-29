# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babkar <babkar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 23:52:21 by babkar            #+#    #+#              #
#    Updated: 2023/01/28 20:55:57 by babkar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS =  -Wextra -Wall -Werror

HEADERS =  srcs/cub3D.h srcs/utils/utils.h srcs/parsing/parsing.h srcs/initialization/initialization.h

SRCS = srcs/main.c \
srcs/initialization/initialize_struct.c \
srcs/initialization/player_init.c \
srcs/initialization/ray_init.c \
srcs/initialization/textures_init.c \
srcs/initialization/window.c \
srcs/parsing/skip_spaces.c \
srcs/parsing/check_map_utils.c \
srcs/parsing/check_map.c \
srcs/parsing/parse_identifiers.c \
srcs/parsing/parse_map.c \
srcs/parsing/parse.c \
srcs/parsing/parse_utils.c \
srcs/parsing/parse_second_identifiers.c \
srcs/game/casting_rays.c \
srcs/game/render_walls.c \
srcs/game/render.c \
srcs/game/update_player_position.c \
srcs/game/wall_collision_sliding.c \
srcs/utils/check_white_space.c \
srcs/utils/create_trgb.c \
srcs/utils/degree_to_radian.c \
srcs/utils/distance_between_two_points.c \
srcs/utils/ft_atoi.c \
srcs/utils/ft_bzero.c \
srcs/utils/ft_calloc.c \
srcs/utils/ft_free.c \
srcs/utils/ft_isdigit.c \
srcs/utils/ft_memset.c \
srcs/utils/ft_putstr_fd.c \
srcs/utils/ft_realloc.c \
srcs/utils/ft_split.c \
srcs/utils/ft_strchr.c \
srcs/utils/ft_strdup.c \
srcs/utils/ft_strlcpy.c \
srcs/utils/ft_strlen.c \
srcs/utils/ft_strncmp.c \
srcs/utils/my_mlx_pixel_put.c \
srcs/utils/ft_substr.c \
srcs/utils/puterr.c \
srcs/utils/get_next_line.c \
srcs/utils/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 
	
$(NAME) : $(OBJS) 
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all, clean, fclean, re