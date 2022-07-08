/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_begin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:51:47 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 20:20:10 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_fixedstack	ft_init(char **argv)
{
	t_fixedstack	a;
	int				i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (ft_isdigit_str(argv[i]) == 1)
		{
			a.big[i] = ft_atoi_exit((const char *)argv[i]);
		}
		else
			ft_error();
		i++;
	}
	return (a);
}

int	ft_check_ident(t_stacks stacks)
{
	int	i;
	int	id;

	id = 1;
	i = 0;
	while (i < stacks.len - 1)
	{
		if (stacks.a.big[i] > stacks.a.big[i + 1])
			id = 0;
		i++;
	}
	return (id);
}
