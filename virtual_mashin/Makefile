# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itsuman <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 18:22:44 by itsuman           #+#    #+#              #
#    Updated: 2017/08/09 18:36:47 by itsuman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	corewar

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ../assembler/libft

LIB_DIR2 = ../assembler/ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

HEADER_DIR2 = ../assembler/libft

HEADER_DIR3 = ../assembler/ft_printf

HEAD_ALL = -I $(HEADER_DIR2) -I $(HEADER_DIR3)

FLAGS = -Wall -Werror -Wextra

SRC = main.c error_manager.c controller.c model.c free_memory.c \
		start_process.c \
		check_live.c run_process.c visualise.c use.c \
		operations/live.c \
		operations/aff.c \
		operations/ft_fork.c \
		operations/lfork.c \
		operations/and.c \
		operations/or.c \
		operations/xor.c \
		operations/zjmp.c \
		operations/ld.c \
		operations/lld.c \
		operations/ldi.c \
		operations/sti.c \
		operations/add.c \
		operations/sub.c \
		operations/st.c \
		operations/lldi.c

OSRC =	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	gcc -o $(NAME) $(FLAGS) $(OSRC) $(LIB_ALL) -lncurses
	
%.o: %.c
	gcc -g $(FLAGS) $(HEAD_ALL) -c -o $@ $<

clean:
	rm -f $(OSRC)

fclean: clean

re: fclean all
