/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:14:40 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/15 03:51:34 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static const char	*ft_symbol_flag(const char *nptr, int *symbol_flag)
{
	*symbol_flag = 1;
	if (*nptr == '-')
	{
		nptr++;
		*symbol_flag = -1;
	}
	else if (*nptr == '+')
		nptr++;
	return (nptr);
}

static int	ft_isspace(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *nptr)
{
	long	num;
	int		symbol_flag;

	while (ft_isspace(*nptr))
		nptr++;
	nptr = ft_symbol_flag(nptr, &symbol_flag);
	num = 0;
	while (ft_isdigit(*nptr))
	{
		if (symbol_flag == 1 && (num > ((LONG_MAX - (*nptr - 48))
					* symbol_flag) / 10))
			return ((int)LONG_MAX);
		else if (symbol_flag == -1 && (num < ((LONG_MIN - (*nptr - 48))
					* symbol_flag) / 10))
			return ((int)LONG_MIN);
		num = (10 * num) + ((*nptr - 48) * symbol_flag);
		nptr++;
	}
	return ((int)num);
}
