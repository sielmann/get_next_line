#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chrmarti <chrmarti@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 13:46:33 by chrmarti          #+#    #+#              #
#    Updated: 2023/10/25 14:55:48 by chrmarti         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = get_next_line
HEADER = get_next_line.h

CC = cc
CFLAGS = -D BUFFER_SIZE=42 -MMD

RM = rm -f

SRCS = main.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:%.c=%.o)
DEPS = $(OBJS:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c %.d
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
