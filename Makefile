# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babkar <babkar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 23:52:21 by babkar            #+#    #+#              #
#    Updated: 2023/01/17 21:24:51 by babkar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CFLAGS =  -Wextra -Wall -Werror

HEADERS =  srcs/cub3D.h utils/utils.h

SRCS = srcs/main.c \
srcs/casting_rays.c \
srcs/check_map_utils.c \
srcs/check_map.c \
srcs/draw_line.c \
srcs/draw_square.c \
srcs/my_mlx_pixel_put.c \
srcs/parse_identifiers.c \
srcs/parse_map.c \
srcs/parse_second_identifiers.c \
srcs/parse_utils.c \
srcs/parse.c \
srcs/player_init.c \
srcs/render_mini_map.c \
srcs/render_walls.c \
srcs/render.c \
srcs/skip_spaces.c \
srcs/textures_init.c \
srcs/update_player_position.c \
srcs/window.c \
utils/bresenham.c \
utils/create_trgb.c \
utils/degree_to_radian.c \
utils/distance_between_two_points.c \
utils/ft_atoi.c \
utils/ft_bzero.c \
utils/ft_calloc.c \
utils/ft_free.c \
utils/ft_isdigit.c \
utils/ft_memset.c \
utils/ft_putstr_fd.c \
utils/ft_realloc.c \
utils/ft_split.c \
utils/ft_strchr.c \
utils/ft_strlen.c \
utils/ft_strncmp.c \
utils/ft_substr.c \
utils/print_map.c \
utils/puterr.c \
utils/get_next_line.c \
utils/get_next_line_utils.c \

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