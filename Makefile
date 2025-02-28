# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/24 00:15:38 by mafzal            #+#    #+#              #
#    Updated: 2025/02/28 20:51:31 by mafzal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source and object files
SRCS = src/get_next_line.c \
       includes/ft_strchr.c \
       includes/ft_strcpy.c \
       includes/ft_strdup.c \
       includes/ft_strjoin.c \
       includes/ft_strlen.c \
       includes/ft_substr.c \
       includes/get_next_line_utils.c \
       main.c  # Include main.c

OBJS = $(SRCS:.c=.o)

# Output file name
NAME = test_function

# All targets
all: $(NAME)

# Linking object files into final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to create object files from source files
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: includes/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
