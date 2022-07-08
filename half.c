/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   half.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:41:09 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:18:02 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_fixedstack	copy_blen(t_fixedstack b, int bstacklen)
{
	t_fixedstack	temp;
	int				j;

	j = 0;
	while (j < bstacklen)
	{
		temp.small[j] = b.small[j];
		j++;
	}
	return (temp);
}

static t_stacks	copy_blen_stack(t_fixedstack b, t_stacks stacks)
{
	int	j;

	j = 0;
	while (j < stacks.bstacklen)
	{
		stacks.b.small[j] = b.small[j];
		j++;
	}
	return (stacks);
}

static t_stacks	half_ops(t_stacks stacks, int len, int mid, int i)
{
	int	j;

	j = 0;
	while (j < (len / 2))
	{
		if (stacks.a.big[0] < mid)
		{
			stacks.stackb[i][len / 2 - j - 1] = stacks.a.big[0];
			stacks = ft_pb(stacks);
			write(1, "pb\n", 3);
			j++;
		}
		else
		{
			stacks = ft_do_r('a', stacks);
			if (stacks.swap != 0)
				stacks.copied++;
		}
	}
	return (stacks);
}

t_stacks	ft_half(t_stacks stacks, int i)
{
	int				mid;
	t_fixedstack	copy;
	int				len;

	len = stacks.lena;
	copy = copy_blen(stacks.b, stacks.bstacklen);
	stacks = copy_blen_stack(copy, stacks);
	copy = ft_copy(stacks.a, stacks.lena);
	mid = median(stacks.lena, copy, 'a');
	stacks.copied = 0;
	stacks = half_ops(stacks, len, mid, i);
	while (stacks.copied != 0)
	{
		stacks = ft_do_rr('a', stacks);
		stacks.copied--;
	}
	return (stacks);
}
