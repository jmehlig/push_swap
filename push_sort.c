/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:58:19 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/17 15:05:30 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_fixedstack	ft_copy(t_fixedstack a, int len)
{
	int				i;
	t_fixedstack	copy;

	i = 0;
	while (i < len)
	{
		copy.big[i] = a.big[i];
		i++;
	}
	return (copy);
}

static t_stacks	ft_sort_three_a(t_stacks stacks)
{
	if ((stacks.a.big[2] < stacks.a.big[0]
			&& (stacks.a.big[2] < stacks.a.big[1]))
		|| (stacks.a.big[0] > stacks.a.big[1]
			&& stacks.a.big[1] < stacks.a.big[2]
			&& stacks.a.big[0] > stacks.a.big[2]))
		stacks = ft_do_rr('a', stacks);
	if (stacks.a.big[1] > stacks.a.big[0]
		&& (stacks.a.big[1] > stacks.a.big[2]))
		stacks = ft_do_rr('a', stacks);
	if (stacks.a.big[1] < stacks.a.big[0])
		stacks = ft_do_s('a', stacks);
	return (stacks);
}

t_stacks	ft_sort(t_stacks stacks)
{
	if (stacks.lena == 3)
	{
		stacks = ft_sort_three_a(stacks);
	}
	else if (stacks.lena == 2)
	{
		if (stacks.a.big[0] > stacks.a.big[1])
			stacks = ft_do_rr('a', stacks);
	}
	if (stacks.b.small[0] == 2)
	{
		if (stacks.b.big[0] < stacks.b.big[1])
			stacks = ft_do_s('b', stacks);
		stacks = ft_do_p('a', stacks);
		stacks = ft_do_p('a', stacks);
		stacks = renew_stackb(stacks);
	}
	else
		stacks = sort_long_b(stacks);
	return (stacks);
}

t_stacks	get_blen(t_stacks stacks)
{
	int	i;
	int	len;
	int	temp;

	i = 0;
	temp = 1;
	len = stacks.len;
	while (len > 3)
	{
		if (len % 2 == 0)
			temp = 0;
		else
			temp = 1;
		len = len / 2;
		if (len == 1)
			len++;
		stacks.b.small[stacks.bstacklen - 1 - i] = len;
		if (temp == 1)
			len++;
		i++;
	}
	if (i == 1)
		stacks.b.small[1] = 0;
	return (stacks);
}

int	get_sections(t_stacks stacks)
{
	int		i;
	float	len;

	i = 0;
	len = stacks.len;
	while (len > 3)
	{
		len = len / 2;
		i++;
	}
	return (i);
}
