/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:16:33 by jmehlig           #+#    #+#             */
/*   Updated: 2022/01/13 15:41:20 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '0'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi_exit(const char *str)
{
	long	dest;
	long	sign;

	dest = 0;
	sign = 1;
	while (*str != '\0' && ft_space(*str) == 1)
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		dest = dest * 10 + ((int)*str - '0');
		if (dest > 2147483647 && sign == 1)
			ft_error();
		if (dest > 2147483648 && sign == -1)
			ft_error();
		str++;
	}
	return (dest * sign);
}
