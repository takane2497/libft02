/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takonaga <takonaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 23:40:22 by takonaga          #+#    #+#             */
/*   Updated: 2022/10/20 00:17:25 by takonaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	count_digits(long tmp)
{
	size_t	count;

	count = 0;
	while (tmp != 0)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

void	do_it(long tmp, char *ret, size_t count, size_t *cycle)
{
	long	s1;
	long	s2;
	char	c;

	s1 = tmp / 10;
	s2 = tmp % 10;
	if (s1 != 0)
	{
		do_it(s1, ret, count, cycle);
		ret += *cycle;
	}
	c = s2 + '0';
	*ret = c;
	*cycle += 1;
	if (conut )
}

char	*ft_itoa(int n)
{
	long	tmp;
	size_t	count;
	char	*ret;
	size_t	cycle;

	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		tmp = -tmp;
	count = count_digits(tmp);
	if (n < 0)
		ret = (char *)malloc(sizeof(char) * (count +2));
	else
		ret = (char *)malloc(sizeof(char) * (count +1));
	if (ret == NULL)
		return (NULL);
	if (n < 0)
		*ret++ = '-';
	cycle = 0;
	do_it(tmp, ret, count, &cycle);
	if (n < 0)
		return (ret - 1);
	return (ret);
}
