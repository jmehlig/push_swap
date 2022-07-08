/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:28:11 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/17 15:06:55 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct fixed_stacks
{
	int	big[4000];
	int	small[20];
}		t_fixedstack;

typedef struct s_stacks
{
	t_fixedstack	a;
	t_fixedstack	b;
	t_fixedstack	number;
	int				len;
	int				lena;
	int				lenb;
	int				stackb[20][500];
	int				bstacklen;
	int				copied;
	int				swap;
}					t_stacks;

t_fixedstack	ft_init(char **argv);
t_stacks		ft_half(t_stacks stacks, int i);
void			ft_error(void);
int				ft_atoi_exit(const char *str);
t_fixedstack	ft_s(t_fixedstack stack, int lenstack);
t_stacks		ft_pb(t_stacks	stacks);
t_stacks		ft_pa(t_stacks	stacks);
t_fixedstack	ft_r(t_fixedstack stack, int lenstack);
t_fixedstack	ft_rr(t_fixedstack stack, int lenstack);
t_stacks		ft_do_s(char c, t_stacks stacks);
t_stacks		ft_do_p(char c, t_stacks stacks);
t_stacks		ft_do_r(char c, t_stacks stacks);
t_stacks		ft_do_rr(char c, t_stacks stacks);
t_stacks		ft_sort_three(char c, t_stacks stacks);
t_fixedstack	quicksort(t_fixedstack number, int first, int last);
int				median(int n, t_fixedstack number, char k);
void			ft_test(t_stacks stacks);
int				get_sections(t_stacks stacks);
t_stacks		ft_sort_begin(t_stacks stacks);
t_stacks		ft_sort(t_stacks stacks);
int				ft_check_ident(t_stacks stacks);
t_stacks		ft_resort_stackb(t_stacks stacks, int j);
t_stacks		ft_swap_b(t_stacks stacks);
t_stacks		copy_stacks(t_stacks stacks);
t_stacks		new_a(t_stacks stacks, t_stacks copy);
t_stacks		sort_b_two(t_stacks stacks);
t_stacks		ft_halfb(t_stacks stacks);
t_stacks		sort_b_two(t_stacks stacks);
t_stacks		renew_stackb(t_stacks stacks);
t_fixedstack	ft_copy(t_fixedstack stack, int len);
t_stacks		b_swap(t_stacks stacks);
t_stacks		print_stackb(t_stacks stacks);
t_stacks		get_blen(t_stacks stacks);
t_stacks		quick_three(t_stacks stacks, int sb);
t_stacks		ft_input(t_stacks stacks, int argc, char **argv);
int				ft_isdigit_str(char	*s);
int				ft_space(char c);
t_stacks		ft_sort_three_b(t_stacks stacks);
t_stacks		sort_four(t_stacks stacks);
t_stacks		sort_long_b(t_stacks stacks);
t_stacks		ft_duplicate(t_stacks stacks);
void			just_one(char **argv);

#endif
