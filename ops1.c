/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:04:07 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:20:01 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_fixedstack	ft_s(t_fixedstack stack, int lenstack)
{
	int	temp;

	if (lenstack < 2)
		return (stack);
	temp = stack.big[0];
	stack.big[0] = stack.big[1];
	stack.big[1] = temp;
	return (stack);
}

t_stacks	ft_pb(t_stacks	stacks)
{
	int	i;
	int	temp;

	i = 0;
	if (stacks.lena == 0)
		return (stacks);
	temp = stacks.a.big[0];
	while (i < stacks.lena)
	{
		stacks.a.big[i] = stacks.a.big[i + 1];
		i++;
	}
	stacks.lena--;
	i = stacks.lenb;
	while (i > 0)
	{
		stacks.b.big[i] = stacks.b.big[i - 1];
		i--;
	}
	stacks.b.big[0] = temp;
	stacks.lenb++;
	return (stacks);
}

t_stacks	ft_pa(t_stacks	stacks)
{
	int	i;
	int	temp;

	i = 0;
	if (stacks.lenb == 0)
		return (stacks);
	temp = stacks.b.big[0];
	while (i < stacks.lenb)
	{
		stacks.b.big[i] = stacks.b.big[i + 1];
		i++;
	}
	stacks.lenb--;
	i = stacks.lena;
	while (i > 0)
	{
		stacks.a.big[i] = stacks.a.big[i - 1];
		i--;
	}
	stacks.a.big[0] = temp;
	stacks.lena++;
	stacks.b.small[0]--;
	return (stacks);
}

t_fixedstack	ft_r(t_fixedstack stack, int lenstack)
{
	int	temp;
	int	i;

	if (lenstack == 0)
		return (stack);
	i = 0;
	temp = stack.big[0];
	while (i < lenstack)
	{
		stack.big[i] = stack.big[i + 1];
		i++;
	}
	stack.big[lenstack - 1] = temp;
	return (stack);
}

t_fixedstack	ft_rr(t_fixedstack stack, int lenstack)
{
	int	temp;
	int	i;

	if (lenstack == 0)
		return (stack);
	i = lenstack - 1;
	temp = stack.big[i];
	while (i > 0)
	{
		stack.big[i] = stack.big[i - 1];
		i--;
	}
	stack.big[0] = temp;
	return (stack);
}
