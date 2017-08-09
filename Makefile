# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/22 18:55:04 by sprotsen          #+#    #+#              #
#    Updated: 2017/07/22 18:55:06 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:	lib
	mv assembler/asm .
	mv virtual_mashin/corewar .

lib:
	make -C assembler
	make -C virtual_mashin

clean:
	make clean -C assembler
	make clean -C virtual_mashin

fclean:	clean
	make fclean -C assembler
	make fclean -C virtual_mashin
	rm -f asm
	rm -f corewar

re: fclean lib all	
