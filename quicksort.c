/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:29:43 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/17 15:05:19 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_fixedstack	ft_change(t_fixedstack number, int i, int j)
{
	int	temp;

	temp = number.big[i];
	number.big[i] = number.big[j];
	number.big[j] = temp;
	return (number);
}

int	median(int n, t_fixedstack number, char k)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (number.big[j] < number.big[i])
				number = ft_change(number, i, j);
			j++;
		}
		i++;
	}
	i = k;
	return (number.big[n / 2]);
}

t_stacks	ft_sort_begin(t_stacks stacks)
{
	int	i;
	int	half;

	i = 1;
	if (ft_check_ident(stacks) == 1 && stacks.swap != 1)
		exit(0);
	else if (ft_check_ident(stacks) == 1)
		return (stacks);
	half = stacks.lena / 2;
	stacks.bstacklen = get_sections(stacks);
	stacks = get_blen(stacks);
	while (stacks.lena > 3)
	{
		stacks = ft_half(stacks, stacks.bstacklen - i);
		i++;
	}
	stacks = ft_sort(stacks);
	while (stacks.lenb != 0)
	{
		stacks = ft_swap_b(stacks);
	}
	return (stacks);
}
