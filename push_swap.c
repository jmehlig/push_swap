/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 12:30:57 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/17 15:07:12 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_space(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s == ' ')
			count++;
		else if (ft_space(*s) == 1 && *s != '0')
			ft_error();
		s++;
	}
	return (count);
}

static t_stacks	copy_blen_stack(t_fixedstack stack, t_stacks stacks)
{
	int	j;

	j = 0;
	while (j < stacks.len)
	{
		stacks.a.big[j] = stack.big[j];
		j++;
	}
	return (stacks);
}

t_stacks	ft_input(t_stacks stacks, int argc, char **argv)
{
	t_fixedstack	temp;
	char			**split;

	if (argc > 2)
	{
		argv++;
		temp = ft_init(argv);
		stacks.len = argc - 1;
		stacks = copy_blen_stack(temp, stacks);
	}
	else if (argc == 2)
	{
		stacks.len = ft_count_space(argv[1]) + 1;
		if (stacks.len == 1)
			just_one(argv);
		split = ft_split((const char *)argv[1], ' ');
		temp = ft_init(split);
		ft_free_double(split);
		stacks = copy_blen_stack(temp, stacks);
	}
	else
		exit(1);
	return (stacks);
}

int	ft_isdigit_str(char	*s)
{
	int	status;
	int	j;
	int	i;

	status = 1;
	j = 0;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 0)
			status = 0;
		i++;
		j = 1;
	}
	if (j == 0 && s[0] == '-')
		status = 0;
	return (status);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.len = 0;
	stacks = ft_input(stacks, argc, argv);
	stacks = ft_duplicate(stacks);
	if (ft_check_ident(stacks) == 1)
		exit(0);
	stacks.lena = stacks.len;
	stacks.lenb = 0;
	if (stacks.lena == 3)
		quick_three(stacks, 0);
	else
		stacks = ft_sort_begin(stacks);
	return (0);
}
