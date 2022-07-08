/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:37:26 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:24:03 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	new_a(t_stacks stacks, t_stacks copy)
{
	int	i;

	i = 0;
	while (i < stacks.copied)
	{
		copy.a.big[i] = stacks.a.big[i];
		i++;
	}
	copy.a.big[i] = INT_MAX;
	return (copy);
}

t_stacks	copy_stacks(t_stacks stacks)
{
	t_stacks	copy;

	copy.len = stacks.copied + 1;
	copy = new_a(stacks, copy);
	copy.lena = copy.len;
	copy.lenb = 0;
	copy.copied = 0;
	copy.b.small[1] = stacks.b.small[1];
	return (copy);
}

t_stacks	get_changed_a(t_stacks stacks, int j, t_stacks temp)
{
	int	i;

	i = 0;
	while (i < temp.lena - 1)
	{
		stacks.a.big[i] = temp.a.big[i + j];
		i++;
	}
	return (stacks);
}

t_stacks	ft_swap_b(t_stacks stacks)
{
	t_stacks	temp;
	int			i;
	int			j;

	while (stacks.lenb > 3)
	{
		if (stacks.b.small[0] == 2)
			stacks = sort_b_two(stacks);
		else
		{
			stacks = ft_halfb(stacks);
			temp = copy_stacks(stacks);
			if (stacks.lenb != 0)
				temp.swap = 1;
			temp = ft_sort_begin(temp);
			i = 0;
			j = i;
			if (temp.a.big[0] == INT_MIN)
				j++;
			i = temp.lena - 1;
			stacks = get_changed_a(stacks, j, temp);
		}
	}
	return (ft_sort(stacks));
}
