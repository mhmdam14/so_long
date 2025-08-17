# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mal-moha <mal-moha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/31 10:59:08 by mal-moha          #+#    #+#              #
#    Updated: 2025/08/11 11:30:12 by mal-moha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_FILES = \
	checker.c \
	end.c \
	errors.c \
	free_allocations.c \
	file_to_image.c \
	generate_map.c \
	keyhook.c \
	movement.c \
	print.c \
	validate_path.c \
	so_long.c

OBJS = $(SRC_FILES:.c=.o)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(OBJS))

INCLUDES = -I. -Ilibft -Iminilibx-linux
LIBS = -Llibft -lft -Lminilibx-linux -lmlx -lXext -lX11 -lm

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ_FILES)
	make -C libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ_FILES) $(INCLUDES) $(LIBS) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C libft clean
	make -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
