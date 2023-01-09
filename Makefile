# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babkar <babkar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 23:52:21 by babkar            #+#    #+#              #
#    Updated: 2023/01/05 18:06:17 by babkar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CFLAGS =  -Wextra -Wall -Werror
LIBFT_PATH = libft/

HEADERS = libft/libft.h srcs/cub3d.h utils/utils.h
LIBFT = $(addprefix $(LIBFT_PATH), libft.a)
SRCS = srcs/main.c \
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
srcs/update_player_position.c \
srcs/window.c \
utils/degree_to_radian.c \
utils/ft_realloc.c \
utils/print_map.c \
utils/puterr.c \
utils/get_next_line.c \
utils/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all : libft  $(NAME)

libft:
	make -C $(LIBFT_PATH)
	
%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ 
	
$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	
re: fclean all

.PHONY: all, clean, fclean, re, libft