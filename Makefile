# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarbajo <acarbajo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 14:45:50 by acarbajo          #+#    #+#              #
#    Updated: 2025/10/22 17:54:29 by acarbajo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I inc -I inc/libft

SRCDIR = src

SRCS = $(SRCDIR)/main.c $(SRCDIR)/ps_utils.c $(SRCDIR)/ps_utils_2.c $(SRCDIR)/ps_parser.c $(SRCDIR)/ps_moves.c \
		$(SRCDIR)/ps_moves_1.c $(SRCDIR)/ps_moves_2.c $(SRCDIR)/ps_moves_3.c $(SRCDIR)/ps_sort_small.c \
		$(SRCDIR)/ps_radix_chunks_utils.c $(SRCDIR)/ps_radix_chunks.c \

OBJDIR = objs

OBJFILES = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

LIBFT_DIR = inc/libft

LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(OBJDIR) $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@echo "Compilando libft..."
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJFILES) $(LIBFT_A)
	@echo "Enlazando $(NAME)..."
	$(CC) $(CFLAGS) $(OBJFILES) $(LIBFT_A) -o $(NAME)
	@echo "Compilación completada!"

$(OBJDIR):
	@mkdir -p $(OBJDIR)


$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "⚙️  Compilando $<..."
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Limpiando objetos..."
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJDIR)

fclean: clean
	@echo "Limpiando binarios..."
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

