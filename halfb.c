/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   halfb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:50:31 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:19:53 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stacks	halfb_ops(t_stacks stacks, int len, int temp, int r_count)
{
	int	j;

	j = 0;
	while (((len % 2 == 0) && (j < (len / 2)))
		|| (len % 2 == 1 && j < len / 2 + 1))
	{
		if (stacks.b.big[0] >= temp)
		{
			stacks = ft_do_p('a', stacks);
			j++;
		}
		else
		{
			stacks = ft_do_r('b', stacks);
			r_count++;
		}
	}
	stacks.copied = j;
	while (r_count > 0 && (stacks.lenb > stacks.b.small[0]
			|| stacks.swap != 0))
	{
		stacks = ft_do_rr('b', stacks);
		r_count--;
	}
	return (stacks);
}

t_fixedstack	ft_copy_stack(t_stacks stacks)
{
	int				i;
	t_fixedstack	copy;

	i = 0;
	while (i < stacks.b.small[0])
	{
		copy.big[i] = stacks.stackb[0][i];
		i++;
	}
	return (copy);
}

t_stacks	ft_halfb(t_stacks stacks)
{
	int				r_count;
	t_fixedstack	copy;
	int				j;
	int				len;
	int				temp;

	copy = ft_copy_stack(stacks);
	len = stacks.b.small[0];
	r_count = 0;
	temp = median(len, copy, 'b');
	if (stacks.lenb == 5)
	{
		temp++;
		len--;
	}
	stacks = halfb_ops(stacks, len, temp, r_count);
	j = 0;
	while (j < stacks.b.small[0])
	{
		stacks.stackb[0][j] = stacks.b.big[j];
		j++;
	}
	stacks = renew_stackb(stacks);
	return (stacks);
}
