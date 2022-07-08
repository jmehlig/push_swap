/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:36:38 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:14:11 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	ft_do_s(char c, t_stacks stacks)
{
	if (c == 'a')
	{
		stacks.a = ft_s(stacks.a, stacks.lena);
		write(1, "sa\n", 3);
	}
	if (c == 'b')
	{
		stacks.b = ft_s(stacks.b, stacks.lenb);
		write(1, "sb\n", 3);
	}
	if (c == 's')
	{
		stacks.a = ft_s(stacks.a, stacks.lena);
		stacks.b = ft_s(stacks.b, stacks.lenb);
		write(1, "ss\n", 3);
	}
	return (stacks);
}

t_stacks	ft_do_p(char c, t_stacks stacks)
{
	if (c == 'a')
	{
		stacks = ft_pa(stacks);
		if (stacks.swap == 2 && stacks.lenb == 1)
			return (stacks);
		write(1, "pa\n", 3);
	}
	if (c == 'b')
	{
		stacks = ft_pb(stacks);
		write(1, "pb\n", 3);
	}
	return (stacks);
}

t_stacks	ft_do_r(char c, t_stacks stacks)
{
	if (c == 'a')
	{
		stacks.a = ft_r(stacks.a, stacks.lena);
		write(1, "ra\n", 3);
	}
	if (c == 'b')
	{
		stacks.b = ft_r(stacks.b, stacks.lenb);
		write(1, "rb\n", 3);
	}
	if (c == 's')
	{
		stacks.a = ft_r(stacks.a, stacks.lena);
		stacks.b = ft_r(stacks.b, stacks.lenb);
		write(1, "rr\n", 3);
	}
	return (stacks);
}

t_stacks	ft_do_rr(char c, t_stacks stacks)
{
	if (c == 'a')
	{
		stacks.a = ft_rr(stacks.a, stacks.lena);
		write(1, "rra\n", 4);
	}
	if (c == 'b')
	{
		stacks.b = ft_rr(stacks.b, stacks.lenb);
		write(1, "rrb\n", 4);
	}
	if (c == 's')
	{
		stacks.a = ft_rr(stacks.a, stacks.lena);
		stacks.b = ft_rr(stacks.b, stacks.lenb);
		write(1, "rrr\n", 4);
	}
	return (stacks);
}
