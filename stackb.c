/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:42:53 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:23:11 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	renew_stackb(t_stacks stacks)
{
	int	i;

	i = 0;
	if (stacks.b.small[0] == 1)
	{
		if (stacks.a.big[0] > stacks.a.big[1])
			stacks = ft_do_s('a', stacks);
		stacks = ft_do_p('a', stacks);
	}
	if (stacks.b.small[0] == 0)
		stacks = ft_resort_stackb(stacks, 0);
	return (stacks);
}

t_stacks	b_swap(t_stacks stacks)
{
	int	i;
	int	len;

	i = 0;
	if (stacks.b.small[0] % 2 == 1 && stacks.b.small[0] != 3)
		stacks.b.small[0]--;
	len = stacks.b.small[0] / 2;
	while (i < len)
	{
		stacks.stackb[0][i] = stacks.b.big[i];
		i++;
	}
	return (stacks);
}

static t_stacks	ft_copy_stays(t_stacks stacks, int i, int j)
{
	int	k;

	k = 0;
	while (k < stacks.b.small[i + j + 1])
	{
		stacks.stackb[i][k] = stacks.stackb[i + j + 1][k];
		k++;
	}
	return (stacks);
}

t_stacks	ft_resort_stackb(t_stacks stacks, int j)
{
	int	i;

	i = 0;
	while (i + j < stacks.bstacklen - 1 && j >= 0)
	{
		stacks = ft_copy_stays(stacks, i, j);
		stacks.b.small[i] = stacks.b.small[i + j + 1];
		i++;
	}
	stacks.b.small[i] = 0;
	stacks.bstacklen = stacks.bstacklen - j - 1;
	return (stacks);
}

t_stacks	sort_b_two(t_stacks stacks)
{
	if (stacks.b.big[0] < stacks.b.big[1])
		stacks = ft_do_s('b', stacks);
	stacks = ft_do_p('a', stacks);
	stacks = ft_do_p('a', stacks);
	stacks = renew_stackb(stacks);
	return (stacks);
}
