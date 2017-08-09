# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/04 13:27:23 by sprotsen          #+#    #+#              #
#    Updated: 2017/06/04 13:27:25 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ./libft

LIB_DIR2 = ./ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

HEADER_DIR = ./includes

HEADER_DIR2 = ./libft

HEADER_DIR3 = ./ft_printf

HEAD_ALL = -I $(HEADER_DIR) -I $(HEADER_DIR2) -I $(HEADER_DIR3)

SRC = 	src_asm/clear_pieces_of_comment_in_line.c \
		src_asm/combination.c \
		src_asm/combination1.c \
		src_asm/combination2.c \
		src_asm/combination2_2_byte.c \
		src_asm/create_cor_file.c \
		src_asm/combination_2_byte.c \
		src_asm/del_file.c \
		src_asm/delete_space.c \
		src_asm/error.c \
		src_asm/create_cor_file_2.c \
		src_asm/find_backslash_n.c \
		src_asm/find_label.c \
		src_asm/find_name_and_comment.c \
		src_asm/for_all_opcode.c \
		src_asm/find_name_and_transformation_to_hex.c \
		src_asm/fun_aff.c \
		src_asm/find_operations.c \
		src_asm/fun_fork.c \
		src_asm/fun_add.c \
		src_asm/fun_ldi.c \
		src_asm/fun_lfork.c \
		src_asm/fun_live.c \
		src_asm/fun_lld.c \
		src_asm/fun_ld.c \
		src_asm/fun_and.c \
		src_asm/fun_or.c \
		src_asm/fun_lldi.c \
		src_asm/fun_sub.c \
		src_asm/fun_st.c \
		src_asm/fun_sti.c \
		src_asm/fun_t_dir_4_byte.c \
		src_asm/fun_t_ind.c \
		src_asm/fun_t_dir_2_byte.c \
		src_asm/fun_xor.c \
		src_asm/fun_zjmp.c \
		src_asm/fun_t_reg.c \
		src_asm/next_validation.c \
		src_asm/main.c \
		src_asm/struct_algo.c \
		src_asm/validation.c \
		src_asm/type_search.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): lib $(OBJ)
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIB_ALL)

%.o: %.c
	gcc $(FLAG) $(HEAD_ALL) -c -o $@ $<

lib:
	make -C libft
	make -C ft_printf

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf

re: fclean lib all
