# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 12:29:05 by xxxxxxx           #+#    #+#              #
#    Updated: 2022/03/23 15:07:29 by xxxxxxx          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

INCLUDE			= ./includes/
SRC_DIR			= ./src/

SRC_FILES		= philo.c utils.c job.c ft.c last_file.c

SRCS			= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS			= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
