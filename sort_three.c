/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:56:20 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:22:57 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_sort_three_b(t_stacks stacks)
{
	if ((stacks.b.big[2] > stacks.b.big[0]
			&& (stacks.b.big[2] > stacks.b.big[1]))
		|| (stacks.b.big[0] < stacks.b.big[1]
			&& stacks.b.big[1] > stacks.b.big[2]
			&& stacks.b.big[0] < stacks.b.big[2]))
		stacks = ft_do_rr('b', stacks);
	if (stacks.b.big[1] < stacks.b.big[0]
		&& (stacks.b.big[1] < stacks.b.big[2]))
		stacks = ft_do_rr('b', stacks);
	if (stacks.b.big[1] > stacks.b.big[0])
		stacks = ft_do_s('b', stacks);
	return (stacks);
}

t_stacks	quick_three(t_stacks stacks, int sb)
{
	if (stacks.a.big[1] > stacks.a.big[0] && stacks.a.big[1] > stacks.a.big[2])
	{
		if (sb == 1)
			stacks = ft_do_rr('s', stacks);
		else
			stacks = ft_do_rr('a', stacks);
		sb = 0;
	}
	if (stacks.a.big[0] > stacks.a.big[1] && stacks.a.big[0] > stacks.a.big[2])
	{
		if (sb == 1)
			stacks = ft_do_r('s', stacks);
		else
			stacks = ft_do_r('a', stacks);
		sb = 0;
	}
	if (stacks.a.big[0] > stacks.a.big[1])
	{
		if (sb == 1)
			stacks = ft_do_s('s', stacks);
		else
			stacks = ft_do_s('a', stacks);
	}
	return (stacks);
}
