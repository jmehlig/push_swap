/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:55:23 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/17 15:06:38 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	sort_four(t_stacks stacks)
{
	stacks.stackb[0][3] = INT_MIN;
	stacks.lenb = 4;
	stacks.b.small [0] = 4;
	stacks.b.big[3] = INT_MIN;
	stacks.swap = 2;
	stacks = ft_swap_b(stacks);
	return (stacks);
}

t_stacks	sort_long_b(t_stacks stacks)
{
	if (stacks.lenb == 3)
	{
		if (stacks.swap == 1)
			return (sort_four(stacks));
		stacks = ft_sort_three_b(stacks);
		stacks = ft_do_p('a', stacks);
		stacks = ft_do_p('a', stacks);
		stacks = ft_do_p('a', stacks);
	}
	else if (stacks.lenb != 0)
		stacks = ft_swap_b(stacks);
	return (stacks);
}

t_stacks	ft_duplicate(t_stacks stacks)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	j = 0;
	temp = stacks.len;
	while (temp > 0)
	{
		while (i < temp)
		{
			if (stacks.a.big[j] == stacks.a.big[i + j])
				ft_error();
			i++;
		}
		temp--;
		j++;
		i = 1;
	}
	return (stacks);
}

void	just_one(char **argv)
{
	ft_atoi_exit(argv[1]);
	if (ft_isdigit_str(argv[1]) == 0)
		ft_error();
	exit (0);
}
