/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head_asm.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/04 13:26:51 by sprotsen          #+#    #+#             */
/*   Updated: 2017/06/04 13:26:53 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_ASM_H
# define HEAD_ASM_H

# include "../libft/libft.h"
# include "../ft_printf/printhead.h"
# include "op.h"
# include "head_algo.h"

# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define L4 unsigned int a
# define L2 unsigned short a

# define FUN_0X54 comb_t_reg_t_reg_t_reg
# define FUN_0X94 comb_t_dir_t_reg_t_reg
# define FUN_0XD4 comb_t_ind_t_reg_t_reg
# define FUN_0X74 comb_t_reg_t_ind_t_reg
# define FUN_0XB4 comb_t_dir_t_ind_t_reg
# define FUN_0XF4 comb_t_ind_t_ind_t_reg
# define FUN_0X64 comb_t_reg_t_dir_t_reg
# define FUN_0XA4 comb_t_dir_t_dir_t_reg
# define FUN_0XE4 comb_t_ind_t_dir_t_reg

# define FUN_0X94_2 comb_t_dir_t_reg_t_reg_2
# define FUN_0X64_2 comb_t_reg_t_dir_t_reg_2
# define FUN_0XA4_2 comb_t_dir_t_dir_t_reg_2
# define FUN_0XE4_2 comb_t_ind_t_dir_t_reg_2

# define FUN_0X58_2 comb_t_reg_t_reg_t_dir_2
# define FUN_0X68_2 comb_t_reg_t_dir_t_dir_2
# define FUN_0X78_2 comb_t_reg_t_ind_t_dir_2

# define LC LABEL_CHAR
# define DC DIRECT_CHAR

# define NEXT_SYMB(x) (x == ' ' || x == LC || x == DC || x == '-') ? 1 : 0
# define NCLINE(x) (x == 0 || (x >= 3000000000 && x <= 3000000002)) ? 1 : 0

void	clear_pieces_of_comment_in_line(t_algo *lst);
void	comment_for_header(t_algo *lst, t_header *head);
void	name_for_header(t_algo *lst, t_header *head);
int		calculate_prog_size(t_algo *lst);
void	write_header(int fd, t_algo *lst);
void	create_cor_file(t_algo *lst, char *str);
void	del_list_list(t_list **list);
void	del_list_algo(t_algo **list);
int		del_list_algo_false(t_algo **list);
int		ft_strdel_char_mass_false(char **mass);
void	delete_space(t_algo *lst);
int		error_message(t_algo *lst, char **mass);
int		find_backslash_n(t_algo *lst, int fd);
void	find_label(t_algo *list);
int		find_name_and_comment(t_algo *list, int count_n, int c_com);
int		comment_and_transformation_to_hex(t_algo *lst, int len, int len_all);
int		name_and_transformation_to_hex(t_algo *lst, int len, int len_all);
void	find_operations(t_algo *lst);
int		pass_space_opcode_space(char *str, int i, int len_opcode);
int		find_len_number(long long a);
void	hex_code(long long a, int i, char *row);
void	create_hex(int n_byte, long long a, t_algo *lst);
int		check_label_name(char *str, t_algo *lst, int len_label, int *index);
int		parsing_t_dir_2_byte_v2(t_algo *lst, char *str, t_algo *list);
int		parsing_t_dir_2_byte(t_algo *lst, int len_opcode_name, t_algo *list);
int		parsing_t_dir_4_byte_v2(t_algo *lst, char *str, t_algo *list);
int		parsing_t_dir_4_byte(t_algo *lst, int len_opcode_name, t_algo *list);
int		parsing_t_ind_v2(t_algo *lst, char *str, t_algo *list);
int		parsing_t_ind(t_algo *lst, t_algo *list);
int		parsing_t_reg_v2(t_algo *lst, char *str);
int		parsing_t_reg(t_algo *lst);
int		next_validation(t_algo *lst);
t_algo	*create_list_algo(char *str, int i);
t_algo	*create_list_algo_new(char *str, int i, int length, char *origin);
void	add_algo(t_algo **alst, t_algo *new);
int		size_algo(t_algo *begin_list);
void	add_algo_center(t_algo **list, t_algo *new);
int		type_search(char **mass, t_algo *lst, int n_param);
int		validation(t_list *list, char *str, int fd);
int		parsing_lldi(t_algo *lst, t_algo *list, int n, int len_name);
int		parsing_ld(t_algo *lst, t_algo *list, int n);
int		parsing_and(t_algo *lst, t_algo *list, int n, int len_name);
int		add_hex_code_and_check_validation(t_algo *lst, long long a, char *str);
t_algo	*giving_len_for_each_list(t_list *lst);
int		review_list_valid(t_algo *list, int i, int flag);
int		find_label_chars(char s);
int		valid_str(char *str, int i, t_algo *lst);
int		error_input(t_algo *lst);
int		error_red(t_algo *lst);
int		fun_live(t_algo *lst);
int		fun_add(t_algo *list);
int		fun_sub(t_algo *list);
int		fun_aff(t_algo *list);
int		fun_zjmp(t_algo *list);
int		fun_fork(t_algo *list);
int		fun_lfork(t_algo *list);
int		fun_ld(t_algo *list);
int		fun_lld(t_algo *list);
int		fun_st(t_algo *list);
int		fun_and(t_algo *list);
int		fun_or(t_algo *list);
int		fun_xor(t_algo *list);
int		fun_lldi(t_algo *list);
int		fun_ldi(t_algo *list);
int		fun_sti(t_algo *list);
int		comb_t_reg_t_reg_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_dir_t_reg_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_ind_t_reg_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_reg_t_ind_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_dir_t_ind_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_ind_t_ind_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_reg_t_dir_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_dir_t_dir_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_ind_t_dir_t_reg(t_algo *lst, char **mass, t_algo *list);
int		comb_t_dir_t_reg_t_reg_2(t_algo *lst, char **mass, t_algo *list);
int		comb_t_reg_t_dir_t_reg_2(t_algo *lst, char **mass, t_algo *list);
int		comb_t_dir_t_dir_t_reg_2(t_algo *lst, char **mass, t_algo *list);
int		comb_t_ind_t_dir_t_reg_2(t_algo *lst, char **mass, t_algo *list);
int		comb_t_reg_t_reg_t_dir_2(t_algo *lst, char **mass, t_algo *list);
int		comb_t_reg_t_dir_t_dir_2(t_algo *lst, char **mass, t_algo *list);
int		comb_t_reg_t_ind_t_dir_2(t_algo *lst, char **mass, t_algo *list);

#endif
