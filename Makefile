# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babkar <babkar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 23:52:21 by babkar            #+#    #+#              #
#    Updated: 2022/12/29 17:42:50 by babkar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CFLAGS =  -Wextra -Wall -Werror
LIBFT_PATH = libft/

HEADERS =
LIBFT = $(addprefix $(LIBFT_PATH), libft.a)
SRCS = srcs/main.c \
srcs/window.c \
srcs/parse_identifiers.c \
srcs/parse_map.c \
srcs/parse_second_identifiers.c \
srcs/parse_utils.c \
srcs/parse.c \
srcs/draw_line.c \
srcs/player_init.c \
utils/puterr.c \
utils/print_map.c \
utils/ft_realloc.c \
gnl/get_next_line.c \
gnl/get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all : libft  $(NAME)

libft:
	make -C $(LIBFT_PATH)
	
%.o : %.c
	$(CC) $(CFLAGS) $(HEADERS) -Imlx -c $< -o $@ 
	
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