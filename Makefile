# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 16:22:28 by myuen             #+#    #+#              #
#    Updated: 2024/11/04 19:43:54 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex
CC		= cc
CFLAGS		= -Wall -Wextra -Werror -g

# Directories
LIBFT_DIR	= ./libft
PRINTF_DIR	= ./ft_printf
GNL_DIR		= ./ft_gnl
OBJ_DIR		= ./obj

# Library Names
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a
GNL		= $(GNL_DIR)/get_next_line.o $(GNL_DIR)/get_next_line_utils.o

# Include paths
INCLUDES	= -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

# Libraries
LIBS		= -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

# Source files
SRCS		= ft_pipex.c ft_init.c ft_cmds.c ft_path.c ft_handle_direct_path.c \
				ft_pipex_utils.c 

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Header files
HEADERS		= ft_pipex.h

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(GNL) $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(GNL):
	$(MAKE) -C $(GNL_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	rm -rf $(OBJ_DIR)/*

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
