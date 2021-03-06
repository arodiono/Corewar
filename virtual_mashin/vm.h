/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itsuman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 17:02:57 by itsuman           #+#    #+#             */
/*   Updated: 2017/06/02 17:03:03 by itsuman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_H
# define _VM_H
# define REG_V1 p[0] == 1 && (v[0] > 0 && v[0] <= 16)
# define REG_V2 p[1] == 1 && (v[1] > 0 && v[1] <= 16)
# include "../assembler/libft/libft.h"
# include "../assembler/ft_printf/printhead.h"
# include "op.h"
# include <stdio.h>
# include <fcntl.h>
# include <ncurses.h>

typedef struct			s_player
{
	unsigned char		id;
	int					number;
	char				*file;
	t_header			*header;
	unsigned char		*prog_cod;
	int					live;
	int					last_live;
	struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int					f;
	int					numb;
	unsigned char		p_id;
	int					p_num;
	int					pc;
	int					live;
	int					carry;
	int					delay;
	int					registers[REG_NUMBER];
	struct s_process	*next;
}						t_process;

typedef struct			s_cycle
{
	int					cycle;
	int					ctd;
	int					max_check;
	int					current;
}						t_cycle;

typedef struct			s_data
{
	struct s_player		*player;
	struct s_process	*prcs;
	struct s_cycle		*ccl;
	unsigned char		map[MEM_SIZE];
	unsigned char		map_v[MEM_SIZE];
	int					dump;
	int					nbr;
	int					v;
	int					amount_players;
	unsigned int		speed;
	int					procnumb;
	struct s_player		*win;
}						t_data;

void					error_manager(char *file, int index);
void					controller(t_player **player);
void					model(t_data **data);
void					start_process(t_data **data);
void					run_process(t_data **data);
void					reset_live(t_data **data);
void					free_player(t_player **player);
void					free_process(t_process **process);
void					live(t_data **data, t_process **process);
void					ld(t_data **data, t_process **process);
void					st(t_data **data, t_process **process);
void					add(t_data **data, t_process **process);
void					sub(t_data **data, t_process **ps);
void					and(t_data **data, t_process **ps);
void					or(t_data **data, t_process **process);
void					xor(t_data **data, t_process **ps);
void					zjmp(t_data **data, t_process **process);
void					ldi(t_data **data, t_process **process);
void					sti(t_data **data, t_process **ps);
void					ft_fork(t_data **data, t_process **process);
void					lld(t_data **data, t_process **ps);
void					lldi(t_data **data, t_process **ps);
void					lfork(t_data **data, t_process **process);
void					aff(t_data **data, t_process **process);
unsigned int			bit_rev(unsigned int octet);
int						is_nbr(char *s);
int						check_arg(char **av, int i, int dump, int players);
int						check_live(t_data **data);
void					add_process(t_data **data, t_process **process,
	int index);
int						get_dir_value(t_data **data, t_process *process,
	int *shift, int dsize);
int						get_ind_value(t_data **data, t_process *process,
	int *shift, int size);
int						get_reg_value(t_data **data, t_process *process,
	int *shift);
int						get_reg_numb(t_data **data, t_process *process,
	int *shift);
int						get_direct(t_data **data, t_process *process,
	int position);
void					load_value(t_data **data, t_process **process,
	int pos, int val);
int						get_ind_address(t_data **data, t_process *process,
	int *shift);
int						get_index_position(int pc, unsigned int val);
int						count_shift(int numb, unsigned char byte, int dir);
void					visualise(t_data **data);
char					is_process(t_process **process, int i);
int						process_count(t_process *process);
void					use(void);

#endif
