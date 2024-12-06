# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myuen <myuen@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 15:35:18 by myuen             #+#    #+#              #
#    Updated: 2024/09/28 16:28:01 by myuen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f

# Directories
LIBFT_DIR = ../libft
PRINTF_DIR = .
OBJ_DIR = obj

# Library Names
LIBFT = $(LIBFT_DIR)/libft.a
NAME = libftprintf.a

# Source Files
PRINTF_SRC = $(PRINTF_DIR)/ft_itobase.c \
             $(PRINTF_DIR)/ft_print_escape.c \
             $(PRINTF_DIR)/ft_print_char.c \
             $(PRINTF_DIR)/ft_printf.c \
             $(PRINTF_DIR)/ft_print_hex.c \
             $(PRINTF_DIR)/ft_print_int.c \
             $(PRINTF_DIR)/ft_print_padding.c \
             $(PRINTF_DIR)/ft_print_pointer.c \
             $(PRINTF_DIR)/ft_print_string.c \
             $(PRINTF_DIR)/ft_print_unsigned.c \
             $(PRINTF_DIR)/ft_process_conversion.c \
             $(PRINTF_DIR)/ft_set_specifiers.c

# Object Files in the obj directory
PRINTF_OBJ = $(PRINTF_SRC:$(PRINTF_DIR)/%.c=$(OBJ_DIR)/%.o)

# Header Files
LIBFTPRINTF_HDR = $(PRINTF_DIR)/ft_printf.h
LIBFT_HDR = $(LIBFT_DIR)/libft.h

# All Target
all: $(LIBFT) $(NAME)
	@echo "🖨️ $(LIBFT) and $(NAME) built!"

# Rule to create libftprintf.a at the root
$(NAME): $(PRINTF_OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $@ $(PRINTF_OBJ)
	@echo "📦 $(NAME) created at the root!"

# Create object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to create object files in obj directory
$(OBJ_DIR)/%.o: $(PRINTF_DIR)/%.c $(LIBFTPRINTF_HDR) $(LIBFT_HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@
	@echo "🛠️  $@ created"

# Build libft.a using its own Makefile
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	@echo "📚 libft.a built!"

# Clean up object files
clean:
	$(RM) $(PRINTF_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 OBJs files cleaned!"

# Clean up all files
fclean: clean
	$(RM) $(NAME)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️  $(NAME) and $(LIBFT) deleted!"

# Rebuild all
re: fclean all
	@echo "🔄 Rebuild complete!"

.PHONY: all clean fclean re
